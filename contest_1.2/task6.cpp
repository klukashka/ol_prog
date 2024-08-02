#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

void dfs(int u, graph& g, vector<int>& been_there, vector<int>& order){
    if (been_there[u] == -1){
        for (int v : g[u]){
            dfs(v, g, been_there, order);
        }
        order.push_back(u);
        been_there[u] = 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    vector<int> been_there(n, -1);
    vector<int> order;
    for (int i = 0; i < n; i++){
        if (been_there[i] == -1){
            dfs(i, g, been_there, order);
        }
    }
    for (int i = order.size() - 1; i > -1; i--){
        cout << order[i] + 1 << ' ';
    }
    cout << '\n';
}