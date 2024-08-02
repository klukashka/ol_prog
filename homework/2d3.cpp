#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18;

struct edge{
    int from, to;
    ll w;
};

using graph = vector<vector<edge>>;

ll maxx(ll a, ll b){
    if (a > b){
        return a;
    }
    return b;
}

struct lca_t{
    int H = 18;
    int n;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<vector<ll>> mx;

    lca_t(const graph g): 
        n(g.size()),
        tin(n),
        tout(n),
        up(n, vector<int>(H)),
        mx(n, vector<ll>(H, -inf)){
            int t = 0;
            dfs(0, t, 0, g);
            for (int i = 1; i < H; i++){
                for (int u = 0; u < n; u++){
                    up[u][i] = up[up[u][i-1]][i-1];
                    mx[u][i] = maxx(mx[u][i-1], mx[up[u][i-1]][i-1]);
                }
            }

        }

    void dfs(int u, int& t, int prev, const graph& g){
        tin[u] = t++;
        for (edge el : g[u]){
            int v = el.to;
            if (v != prev){
                dfs(v, t, u, g);
                up[v][0] = u;
                mx[v][0] = el.w;
            }
        }
        tout[u] = t++;
    }
    
    bool is_upp(int u, int v){
        return (tin[u] < tin[v] && tout[v] < tout[u]);
    }

    int lca(int u, int v){
        if (is_upp(u, v)){
            return u;
        }
        if (is_upp(v, u)){
            return v;
        }
        for (int j = H-1; j >= 0; j--){
            int nu = up[u][j];
            if (!is_upp(nu, v)){
                u = nu;
            }
        }  
        return up[u][0];
    }

    ll dist_up(int u, int v){
        if (u == v){
            return -inf;
        }
        ll res = -inf;
        for (int j = H-1; j >= 0; j--){
            int nu = up[u][j];
            if (!is_upp(nu, v)){
                res = maxx(res, mx[u][j]);
                u = nu;
            }
        }
        return res;
    }

    ll dist(int u, int v){
        int l = lca(u, v);
        return maxx(dist_up(u, l), dist_up(v, l));
    }

};

void solve(){
    int n;
    cin >> n;
    graph g(n);
    for (int i = 0; i < n-1; i++){
        int p;
        ll w;
        cin >> p >> w;
        p--;
        g[p].push_back({p, i+1, w});
        g[i+1].push_back({i+1, p, w});
    }
    lca_t lca(g);
    int q;
    cin >> q;
    while (q--){
        int u, v;
        cin >> u >> v;
        cout << lca.dist(--u, --v) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r; 
    cin >> r;
    while (r--){
        solve();
    }
}