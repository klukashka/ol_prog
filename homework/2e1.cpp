#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

bool kunh(int u, vector<int>& mt, vector<bool>& visited, const graph& g){
    if (visited[u]){
        return false;
    }
    visited[u] = true;
    for (int i : g[u]){
        if (mt[i] == -1){
            mt[i] = u;
            return true;
        }
    }
    for (int i : g[u]){
        if (kunh(mt[i], mt, visited, g)){
            mt[i] = u;
            return true;
        }
    }
    return false;
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
        u--;v--;
        g[u].push_back(v);
    }
    vector<int> mt(n, -1);
    vector<bool> visited(n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        visited.assign(n, false);
        ans += kunh(i, mt, visited, g);
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++){
        if (mt[i] != -1){
            cout << mt[i] + 1 << ' ' << i + 1 << '\n';
        }
    }
}