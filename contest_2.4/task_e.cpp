#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

struct lca_t{
    int H = 18;
    int n;
    int U, V;
    int U_V;
    vector<int> tin, tout, d;
    vector<vector<int>> up;

    lca_t(graph& gr, int start): 
        n(gr.size()),
        U(start),
        V(start),
        U_V(0),
        tin(n),
        tout(n),
        d(n),
        up(n, vector<int>(H)){}
    
    void recount(graph& gr, int start){
        tin[start] = 0;
        tout[start] = 0;
        int t = 0, d_count = 0;
        dfs(start, t, start, gr, d_count);
        up[start][0] = start;
        for (int i = 1; i < H; i++){
            for (int u = 0; u < n; u++){
                if (u != start){
                    up[u][i] = up[up[u][i-1]][i-1];
                } else {
                    up[u][i] = u;
                }
            }
        }
    }

    void dfs(int u, int& t, int prev, const graph& g, int& d_count){
        tin[u] = t++;
        d[u] = d_count++;
        for (int v : g[u]){
            if (v != prev){
                dfs(v, t, u, g, d_count);
                up[v][0] = u;
            }
        }
        d_count--;
        tout[u] = t++;
    }

    int diam(graph& g, int x){
        int u_new = d[lca(U, x)];
        int v_new = d[lca(V, x)];
        int u_v = U_V;
        cout << u_new << ' ' << v_new << u_v << '\n';
        if (u_new > U_V && u_new > v_new){
            V = x;
            U_V = d[U] + d[x] - u_new;
        } else if (v_new > U_V && v_new > u_new){
            U = x;
            U_V = d[V] + d[x] - v_new;
        }
        return U_V;
    }
    
    bool is_upp(int u, int v){
        if (tin[u] < tin[v] && tout[u] > tout[v]){
            return true;
        }
        return false;
    }

    int lca(int u, int v){
        if (is_upp(u, v) || u == v){
            return u;
        }
        if (is_upp(v, u)){
            return v;
        }
        for (int j = H-1; j >= 0; j--){
            int nu = up[u][j];
            // cout << "u, nu :  " << u + 1 << ' ' << nu + 1 << '\n' ;
            if (!is_upp(nu, v)){
                u = nu;
            }
        }
        // cout << "u :  " <<  u + 1 << ' ' << up[u][0] + 1 << '\n';
        return up[u][0];
    }
};

void solve(){
    int n;
    cin >> n;
    graph g(n);
    lca_t tr(g, 0);
    tr.recount(g, 0);
    int x;
    cout << "done\n";
    for (int i = 0; i < n; i++){
        cin >> x;
        x--;
        g[i].push_back(x);
        g[x].push_back(i);
        tr.recount(g, 0);
        cout << tr.diam(g, x) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}