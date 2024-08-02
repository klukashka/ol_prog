#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
const ll inf = 1e18;

int dfs_ch(int cur, vector<int>& children, graph& g){
    for (int v : g[cur]){
        children[cur] += dfs_ch(v, children, g);
    }
    children[cur]++;
    return children[cur];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    graph g(n);
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> children(n, 0);
    vector<int> how_many(n, 0);
    dfs_ch(0, children, g);
    for (int i : children){
        cout << i << '\n';
    }
    
}