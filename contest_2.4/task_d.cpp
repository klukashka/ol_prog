#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge{
    int from, to;
};

using graph = vector<vector<edge>>;

void dfs(int u, int prev, vector<vector<edge>>& g, vector<edge>& edges, vector<ll>& sub){
    ll res = 1;
    for (edge el : g[u]){
        if (el.to != prev){
            edges.push_back(el);
            dfs(el.to, u, g, edges, sub);
            res = res + sub[el.to];
        }
    }
    sub[u] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    graph g(n);
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back({u, v});
        g[v].push_back({v, u});
    }
    vector<edge> edges;
    vector<ll> sub(n);
    dfs(0, 0, g, edges, sub);
    ll total = 0;
    for (edge el : edges){
        total = total + sub[el.to] * (n - sub[el.to]);
    }
    cout << total << '\n';
}