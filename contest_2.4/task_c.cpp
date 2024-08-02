#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct edge{
    ll w;
    int from, to;
};
using graph = vector<vector<edge>>;

void dfs(int u, int prev, graph& g, vector<int>& c, vector<edge>& edges){
    int res = 1;
    for (edge el : g[u]){
        if (el.to != prev){
            edges.push_back(el);
            dfs(el.to, el.from, g, c, edges);
            res += c[el.to];
            // for (int i = 0; i < g.size(); i++){
            //     cout << c[i] << ' ';
            // } cout << el.to + 1 << " \n\n";
        }
    }
    c[u] = res;
}

bool compare(const edge& a, const edge& b){
    return a.w < b.w;
}

void solve(){
    int n, f;
    cin >> n >> f;
    f--;
    graph g(n);
    vector<edge> edges;
    for (int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({w, u, v});
        g[v].push_back({w, v, u});
    }
    vector<int> c(n, -1);
    dfs(f, f, g, c, edges);
    // for (int i = 0; i < g.size(); i++){
    //             cout << c[i] << ' ';
    //         } cout << '\n';
    vector<edge> imp(n-1);
    for (int i = 0; i < n-1; i++){
        if (2 * c[edges[i].to] >= c[edges[i].from]){
            imp[i] = {2 * edges[i].w, edges[i].from, edges[i].to};
        } else {
            imp[i] = {edges[i].w, edges[i].from, edges[i].to};
        }
    }
    sort(imp.begin(), imp.end(), compare);
    for (int i = n-2; i >= 0; i--){
        cout << imp[i].from + 1 << ' ' << imp[i].to + 1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cout << '\n';
        solve();
    }
}