#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

bool dfs(int u, int v, const graph& g, stack<int>& path, vector<int>& been_there){
    if (been_there[u] == -1){
        been_there[u] = 1;
        path.push(u);
        if (u == v){
            return true;
        }
        for (int i = 0; i < g[u].size(); i++){
            bool found = dfs(g[u][i], v, g, path, been_there);
            if (found){
                return true;
            } else {
                continue;
            }
        }
        path.pop();
    }
    return false;
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
        int y, p;
        cin >> y >> p;
        y--;
        p--;
        g[y].push_back(p);
        g[p].push_back(y);
    }
    stack<int> path;
    vector<int> been_there(n, -1);
    bool found = dfs(u, v, g, path, been_there);
    vector<int> ans;
    while (!path.empty()){
        ans.push_back(path.top());
        path.pop();  
    }
    if (found){
        for (int i = ans.size() - 1; i > -1; i--){
            cout << ans[i] + 1 << ' ';
        }
    } else {
        cout << -1;
    }
    cout << '\n';
}