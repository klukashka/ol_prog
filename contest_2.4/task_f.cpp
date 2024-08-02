#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;
using ll = long long;
const ll inf = 1e18;

const int black = 1;
const int green = 2;
const int red = 3;

ll maxx(ll a, ll b){
    if (a > b){
        return a;
    }
    return b;
}

bool dfs(int u, int prev, const graph& g, vector<int>& colour, vector<int>& path, unordered_set<int>& ans, 
vector<unordered_set<int>>& cycles, unordered_set<int>& any_cycle){
    if (colour[u] == red){
        return false;
    }
    if (colour[u] == green){
        return true;
    }
    colour[u] = green;
    path.push_back(u);
    for (int v : g[u]){
        // cout << u + 1 << ' '  << v + 1 << ' ' << path.size() << " path\n";
        if (v == prev || colour[v] == red){
            continue;
        }
        bool found = dfs(v, u, g, colour, path, ans, cycles, any_cycle);
        if (found){
            if (ans.empty()){
                int ind = path.size() - 1;
                while (path[ind] != v){
                    ans.insert(path[ind]);
                    any_cycle.insert(path[ind]);
                    ind--;
                }
                ans.insert(v);
                any_cycle.insert(v);
                // for (const auto& c : ans){
                //     cout<< c + 1 << ' ';
                // } cout << '\n';
                cycles.push_back(ans);
                // cout << cycles.size() << " cycles size\n";
                ans.clear();
            }
        }
    }
    colour[u] = red;
    path.pop_back();
    return false;
}

void pressing_graph(int& n, graph& g, graph& g_new, 
unordered_map<int, int>& elem_leader, const unordered_set<int>& any_cycle){
    vector<unordered_set<int>> g_st(n);
    for (int i = 0; i < n; i++){
        bool found = false;
        if (any_cycle.find(i) != any_cycle.end()){
            found = true;
        }
        if (found){
            int c1 = elem_leader[i];
            for (int v : g[i]){
                bool v_in = false;
                if (any_cycle.find(v) != any_cycle.end()){
                    v_in = true;
                    if (c1 != elem_leader[v]){
                        g_st[c1].insert(elem_leader[v]);
                    }
                }
                if (!v_in){
                    g_st[c1].insert(v);
                }
            }
            continue;
        }
        for (int v : g[i]){
            bool v_in = false;
            if (any_cycle.find(v) != any_cycle.end()){
                v_in = true;
                g_st[i].insert(elem_leader[v]);
            }
            if (!v_in){
                g_st[i].insert(v);
            }
        }
    }
    for (int i = 0; i < n; i++){
        vector<int> v(g_st[i].begin(), g_st[i].end());
        g_new[i] = v;
    }
}

struct lca_t{
    int H = 18;
    int n;
    vector<int> tin, tout, d;
    vector<vector<int>> up;

    lca_t(const graph gr, int start): 
        n(gr.size()),
        tin(n),
        tout(n),
        d(n),
        up(n, vector<int>(H)){
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
    int n, m, f;
    cin >> n >> m >> f;
    f--;
    graph g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // for (int i = 0; i < n; i++){
    //     cout << i + 1 << " :  ";
    //     for (int v : g[i]){
    //         cout << v + 1 << ' ';
    //     }
    //     cout << " g\n";
    // }
    vector<unordered_set<int>> cycles;
    unordered_set<int> any_cycle;
    unordered_set<int> ans;
    vector<int> colour(n, black), path;
    dfs(f, f, g, colour, path, ans, cycles, any_cycle);

    graph g_new(n);
    vector<int> leaders(cycles.size());
    for (int c = 0; c < cycles.size(); c++){
        leaders[c] = *cycles[c].begin();
    }

    // checking if a root is in cycle
    if (any_cycle.find(f) != any_cycle.end()){
        for (int c = 0; c < cycles.size(); c++){
            if (cycles[c].find(f) != cycles[c].end()){
                leaders[c] = f;
                break;
            }
        }
    }

    unordered_map<int, int> elem_leader;
    for (int c = 0; c < cycles.size(); c++){
        int leader = leaders[c];
        for (auto i = cycles[c].begin(); i != cycles[c].end(); i++){
            elem_leader[*i] = leader;
        }
    }

    // pressing the graph
    if (cycles.size() == 0){
        g_new = g;
    } else {
        pressing_graph(n, g, g_new, elem_leader, any_cycle);
    }
    // for (int i = 0; i < n; i++){
    //     cout << i + 1 << " :  ";
    //     for (int v : g_new[i]){
    //         cout << v + 1 << ' ';
    //     }
    //     cout << "  g_new\n";
    // }
    // g.clear();
    lca_t lca(g_new, f);
    // g_new.clear();
    int q;
    cin >> q;
    // for (int i = 0; i < 18; i++){
    //     cout << "up " << i + 1 << " :  ";
    //     for (int j = 0; j < n; j++){
    //         cout << lca.up[i][j] + 1 << " ";
    //     }
    //     cout << '\n';
    // }
    while (q--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        if (any_cycle.find(x) != any_cycle.end()){
            x = elem_leader[x];
        }
        if (any_cycle.find(y) != any_cycle.end()){
            y = elem_leader[y];
        }
        // cout << x + 1<< ' ' << y + 1 << " xy  ";
        // cout << lca.lca(x, y) + 1 << " lca  ";
        cout << lca.d[lca.lca(x, y)] << '\n';
        // for (int i = 0; i < g_new.size(); i++){
        //     cout << lca.d[i] << ' ';
        // }
        // cout << '\n';
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