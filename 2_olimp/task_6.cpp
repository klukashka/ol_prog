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

void print_vector(vector<int> v){
    for (int i = 0; i < v.size();i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;c--;
    graph g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d_1(n, -1), d_2(n, -1), d_3(n, -1);
    bfs(a, g, d_1);
    bfs(b, g, d_2);
    bfs(c, g, d_3);
    // print_vector(d_1);
    // cout << '\n';
    // print_vector(d_2);
    // cout << '\n';
    // print_vector(d_3);
    // cout << '\n';
    for (int i = 0; i < n; i++){
        if (d_1[i] == d_2[i] && d_2[i] == d_3[i]){
            cout << i+1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}  