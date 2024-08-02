#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge{
    ll w;
    int from, to;
};

using graph = vector<vector<edge>>;

struct lca_t{
    int H = 18;
    int n;
    vector<vector<int>> up;
    vector<int> d;

    lca_t(): 
        n(1), d(n), up(n, vector<int>(H)){}

    int go_up(int u, int h){
        for (int i = 0; i < H; i++){
            if (h & 1){
                u = up[u][i];
            }
            h = h >> 1;
        }
        return u;            
    }

    int lca(int u, int v){
        if (d[u] > d[v]){
            swap(u, v);
        }
        v = go_up(v, d[v] - d[u]);
        if (u == v){
            return u;
        }
        for (int j = H-1; j >= 0; j--){
            int nu = up[u][j];
            int nv = up[v][j];
            if (nu != nv){
                u = nu;
                v = nv;
            }
        }
        return up[u][0];
    }

    void add_leaf(int p){
        int u = up.size();
        d.push_back(d[p] + 1);
        up.push_back(vector<int>(H));
        up[u][0] = p;
        for (int i = 1; i < H; i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }
    }

};

bool is_upp(int u, int v, vector<int>& tin, vector<int>& tout){
    if (tin[u] < tin[v] && tout[u] > tout[v]){
        return true;
    }
    return false;
}

void solve(){
    int q;
    cin >> q;
    lca_t lca;
    while (q--){
        char c;
        int u, v;
        cin >> c >> u >> v;
        u--;v--;
        if (c == '?'){
            cout << 1 + lca.lca(u, v) << '\n';
        } else {
            lca.add_leaf(min(u, v));
        }
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