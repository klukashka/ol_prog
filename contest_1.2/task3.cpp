#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

void dfs(int u, const graph& g, vector<int>& been_there, int& timer){
    been_there[u] = timer;
    for (int v : g[u]){
        if (been_there[v] == -1){
            dfs(v, g, been_there, timer);
        } else {
            continue;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++){
        int y, p;
        cin >> y >> p;
        y--;
        p--;
        g[y].push_back(p);
        g[p].push_back(y);
    }
    vector<int> been_there(n, -1);
    int timer = 0;
    for (int i = 0; i < n; i++){
        if (been_there[i] == -1){
            timer++;
            dfs(i, g, been_there, timer);
        } else {
            continue;
        }
    }
    dfs(0, g, been_there, timer);
    cout << timer << '\n';
}