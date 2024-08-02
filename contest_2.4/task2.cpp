#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void dfs(int u, int prev, vector< int>& st, vector< int>& letters, 
        map< int, vector<int>>& where, vector<vector<int>>& g){

    int cur = letters[u];
    for (int v : g[u]){
        if (v == prev){
            continue;
        }
        dfs(v, u, st, letters, where, g);
        cur = cur | st[v];
    }
    st[u] = cur;
    where[cur].push_back(u);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector< int> letter(26);
     int res = 1;
    for (int i = 0; i < 26; i++){
        letter[i] = res;
        res = res * 2;
    }

    int n; 
    cin >> n;
    vector< int> letters(n);
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        letters[i] = letter[c - 'a'];
    }
    // for (int i = 0; i < 26; i++){
    //     cout << letter[i] << ' ';
    // } cout << '\n';
    // for (int i = 0; i < n; i++){
    //     cout << letters[i] << ' ';
    // } cout<< '\n';
    graph g(n);
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector< int> st(n);
    map< int, vector<int>> where;

    dfs(0, 0, st, letters, where, g);
    for (auto const& [key, val] : where){
        if (val.size() > 1){
            cout << val[0] + 1 << ' ' << val[1] + 1 << '\n';
            return 0;   
        }
    }
    cout << "-1 -1\n";
}