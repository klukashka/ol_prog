#include <bits/stdc++.h>
    
using namespace std;
using graph = vector<vector<int>>;
    
void bfs(int start, graph& g, vector<int>& d){
    queue<int> q;
    d[start] = 0;
    q.push(start);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : g[u]){
            if (d[v] != -1){
                continue;
            }
            d[v] = d[u] + 1;
            q.push(v);
        }
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
    vector<int> d(n, -1);
    bfs(k, g, d);
    for (int i : d){
        cout << i << ' ';
    }
    cout << '\n';
}