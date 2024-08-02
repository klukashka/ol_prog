#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;
using pii = pair<int, int>;
using ll = long long;
const int inf = 1e9;

struct item{
    int from, to, w;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    s--;
    f--;
    //vector<pii> edges(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    vector<vector<int>> store(n);
    for (int u = 0; u < n; u++){
        for (int v : g[u]){
            bool need = true;
            for (int k = 0; k < g[v].size(); k++){
                if (u == g[v][k]){
                    need = false;
                    break;
                }
            }
            if (need){
                store[v].push_back(u);
            }
        }
    }
    vector<int> dp(n, inf);
    dp[s] = 0;
    vector<bool> been_there(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({dp[s], s});
    while (q.size()){
        pii cur = q.top();
        q.pop();
        int u = cur.second;
        //cout << u << '\n';
        if (been_there[u]){
            continue;
        }
        been_there[u] = true;
        for (int el : g[u]){
            if (dp[u] < dp[el]){
                dp[el] = dp[u];
                q.push({dp[el], el});
            }        
        }
        for (int el : store[u]){
            if (dp[u] + 1 < dp[el]){
                dp[el] = dp[u] + 1;
                q.push({dp[el], el});
            }
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int v : g[i]){
    //         cout << i + 1 << ' ' <<  v + 1 << '\n';
    //     }
    // }
    // cout << '\n';
    // for (int i = 0; i < n; i++){
    //     for (int v : store[i]){
    //         cout << i + 1 << ' ' <<  v + 1 << '\n';
    //     }
    // }
    // cout << '\n';
    // for (int i = 0; i < n; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    cout << dp[f] << '\n';
}