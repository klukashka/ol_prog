#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

const int black = 1;
const int green = 2;
const int red = 3;

bool dfs(int u, int prev, const graph& g, vector<int>& colour, vector<int>& path, vector<int>& ans){
    if (colour[u] == green){
        return true;
    }
    colour[u] = green;
    path.push_back(u);
    for (int v : g[u]){
        if (v == prev){
            continue;
        } else {
            bool found = dfs(v, u, g, colour, path, ans);
            if (found){
                if (ans.empty()){
                    int ind = path.size() - 1;
                    while (path[ind] != v){
                        ans.push_back(path[ind]);
                        ind--;
                    }
                    ans.push_back(v);
                }
                return true;
            }
        }
    }
    colour[u] = red;
    path.pop_back();
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    graph g(n);
    for (int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> colour(n, black), path, ans;
    dfs(0, 0, g, colour, path, ans);
    sort(ans.begin(), ans.end());
    for (int i : ans){
        cout << i + 1 << ' ';
    }
    cout << '\n';
}