#include <bits/stdc++.h>

using namespace std;


using graph = vector<vector<int>>;

void bfs(int start, graph& g, vector<int>& dist){
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()){
        int  u = q.front();
        q.pop();
        for (int v : g[u]){
            if (dist[v] != -1){
                continue;
            }
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        graph g(n);
        for (int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> dist(n, -1);
        bfs(0, g, dist);
        int mx_ind = 0;
        for (int i = 0; i < n; i++){
            if (dist[mx_ind] < dist[i]){
                mx_ind = i;
            }
        }
        for (int i = 0; i < n; i++){
            dist[i] = -1;
        }
        bfs(mx_ind, g, dist);
        for (int i = 0; i < n; i++){
            if (dist[mx_ind] < dist[i]){
                mx_ind = i;
            }
        }
        cout << dist[mx_ind] << '\n';
    }
}