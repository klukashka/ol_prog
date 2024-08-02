#include <bits/stdc++.h>
    
using namespace std;
using graph = vector<vector<int>>;

void bfs(int start, graph& g, vector<int>& came_from){
    queue<int> q;
    q.push(start);
    came_from[start] = start;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : g[u]){
            if (came_from[v] == -1){
                came_from[v] = u;
                q.push(v);
            }
            // for (int i = 0; i < g.size(); i++){
            //     cout << came_from[i] + 1 << ' ' << i+1 <<'\n';
            // }
            // cout << '\n';
        }
    }
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m >> u >> v;
    u--;
    v--;
    graph g(n);
    for (int i = 0; i < m; i++){
        int uu, vv;
        cin >> uu >> vv;
        uu--;
        vv--;
        g[uu].push_back(vv);
        g[vv].push_back(uu);
    }
    for (int i = 0; i < g.size(); i++){
        sort(g[i].begin(), g[i].end());
    }
    vector<int> came_from(g.size(), -1);
    bfs(u, g, came_from);
    
    if (came_from[v] != -1){
        vector<int> ans = {v};
        int prev = came_from[v];
        while (came_from[prev] != prev){
            ans.push_back(prev);
            prev = came_from[prev];
        }
        if (v != u){
            ans.push_back(prev);
        }
        for (int i = ans.size() - 1; i > -1; i--){
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << -1;
    }
    cout << '\n';
}
