#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using graph = vector<vector<pair<int, int>>>;
using ll = long long;
const int inf = 1e9;

struct item{
    int from, to, w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<item>> g(n);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({u, v, w});
        g[v].push_back({v, u, w});
    }
    vector<int> dp(n, 0);
    dp[s] = inf;
    vector<bool> been_there(n, false);
    priority_queue<pii> q;
    q.push({dp[s], s});
    while (q.size()){
        pii cur = q.top();
        q.pop();
        int u = cur.second;
        if (been_there[u]){
            continue;
        }
        been_there[u] = true;
        for (item v : g[u]){
            if (min(dp[u], v.w) > dp[v.to]){
                dp[v.to] = min(dp[u], v.w);
                q.push({dp[v.to], v.to});
            }
        }
    }
    for (int v : dp){
        if (v == inf){
            cout << -1 << ' ';
        } else {
            cout << v << ' ';
        }
    }
    cout << '\n';
}