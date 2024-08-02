#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

const int black = 0;
const int green = 1;
const int red = 2;

struct info{
    int dot;
    int col;
};

bool bfs(int start, graph& g, vector<int>& colour){
    bool bad_gr = false;
    queue<info> q;
    q.push({start, green});
    while (!q.empty()){
        info u = q.front();
        q.pop();
        if (colour[u.dot] != black && colour[u.dot] != u.col){
            bad_gr = true;
            break;
        }
        if (colour[u.dot] == u.col){
            continue;
        }
        colour[u.dot] = u.col;
        int colour_to_print;
        if (u.col == red){
            colour_to_print = green;
        } else {
            colour_to_print = red;
        }
        for (int v : g[u.dot]){
            q.push({v, colour_to_print});
        }
    }
    return bad_gr;
}

bool kunh(int u, vector<int>& mt, vector<bool>& visited, const graph& g, const vector<int>& colour){
    if (visited[u]){
        return false;
    }
    visited[u] = true;
    for (int i : g[u]){
        if (colour[i] != colour[u]){
            if (mt[i] == -1){
                mt[i] = u;
                return true;
            }
            if (kunh(mt[i], mt, visited, g, colour)){
                mt[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    vector<set<int>> g_check(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        if (g_check[u].find(v) == g_check[u].end() && g_check[v].find(u) == g_check[v].find(u)){
            g[u].push_back(v);
            g_check[u].insert(v);
            g[v].push_back(u);
            g_check[v].insert(u);
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int v : g[i]){
    //         cout << v << ' ';
    //     }
    //     cout << " g\n";
    // }
    //checking for cycles
    vector<int> colour(n, black);
    for (int i = 0; i < n; i++){
        if (colour[i] == black){
            if (bfs(i, g, colour)){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    // for (int i = 0; i < n; i++){
    //     cout << colour[i] << ' ';
    // }

    // if a good graph
    vector<int> mt(n, -1);
    vector<bool> visited(n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (colour[i] == red){
            visited.assign(n, false);
            ans += kunh(i, mt, visited, g, colour);
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++){
        if (mt[i] != -1){
            cout << mt[i] + 1 << ' ' << i + 1 << '\n';
        }
    }
}