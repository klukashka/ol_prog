#include <bits/stdc++.h>
    
using namespace std;
using graph = vector<vector<int>>;
using pii = pair<int, int>;
    
int bfs(int u, graph& g, vector<pii>& path){
    if (path[u].first == 0){
        int longest_u_path = u;
        for (int v : g[u]){
            int local_ans = bfs(v, g, path);
            if (path[longest_u_path].first < path[local_ans].first){
                longest_u_path = local_ans;
            }
        }
        path[u] = {path[longest_u_path].first + 1, longest_u_path};
    }
    return u;
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
    pii p = {0, -1};
    vector<pii> path(n, p);
    for (int i = 0; i < n; i++){
        if (path[i].second == -1){
            bfs(i, g, path);
        } else {
            continue;
        }
    }
    int max_ind = 0;
    for (int i = 1; i < n; i++){
        if (path[i].first > path[max_ind].first){
            max_ind = i;
        }
    }
    cout << path[max_ind].first << '\n';
    int prev = max_ind;
    cout << prev + 1 << ' ';
    while (path[prev].second != prev){
        cout << path[prev].second + 1 << ' ';
        prev = path[prev].second;
    }
    cout << '\n';
}