#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

void dfs(int u, const graph& g, vector<int>& tin, int& timer){
    if (tin[u] != -1){
        return;
    }
    tin[u] = timer;
    timer++;
    for (int v = 0; v < g[u].size(); v++){
        dfs(g[u][v], g, tin, timer);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    graph g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int timer = 0;
    vector<int> tin(n, -1);
    dfs(k, g, tin, timer);
    for (int i = 0; i < tin.size(); i++){
        cout << tin[i] << ' ';
    }
    cout << '\n';
}