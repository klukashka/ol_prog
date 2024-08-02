#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void dfs(int u, int& t, vector<int>& tin, vector<int>& tout, vector<vector<int>>& g){
    tin[u] = t++;
    for (int v : g[u]){
        if (tin[v] == -1){
            dfs(v, t, tin, tout, g);
        }
    }
    tout[u] = t++;
}

bool is_upp(int u, int v, vector<int>& tin, vector<int>& tout){
    if (tin[u] < tin[v] && tout[u] > tout[v]){
        return true;
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    graph g(n);
    vector<int> tin(n, -1);
    vector<int> tout(n, -1);
    for (int i = 0; i < n-1; i++){
        int p;
        cin >> p;
        p--;
        g[p].push_back(i + 1);
        g[i + 1].push_back(p);
    }
    int t = 0;
    dfs(0, t, tin, tout, g);
    int q;
    cin >> q;
    while (q--){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (is_upp(u, v, tin, tout)){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r; 
    cin >> r;
    while (r--){
        solve();
    }
}