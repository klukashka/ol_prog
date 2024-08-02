#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;

struct edge{
    int from, to;
    ll w;
};

using graph = vector<vector<edge>>;
using item = pair<ll, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({u, v, w});
    }
    vector<int> prev(n, -1);
    vector<ll> dp(n, inf);
    dp[0] = 0;
    vector<bool> been_there(n, false);
    priority_queue<item, vector<item>, greater<item>> q;
    q.push({dp[0], 0});
    while (q.size()){
        item cur = q.top();
        q.pop();
        int u = cur.second;
        if (been_there[u]){
            continue;
        }
        been_there[u] = true;
        for (edge el : g[u]){
            if (dp[el.from] + el.w < dp[el.to]){
                dp[el.to] = dp[el.from] + el.w;
                prev[el.to] = el.from;
                q.push({dp[el.to], el.to});
            }
        }
    }
    int finish = n - 1;
    if (prev[finish] == -1){
        cout << -1 << '\n';
        return 0;
    }
    vector<int> path = {finish};
    int u = prev[finish];
    while (u != -1){
        path.push_back(u);
        u = prev[u];
    }
    for (int i = path.size() - 1; i > -1; i--){
        cout << path[i] + 1 << ' ';
    }
    cout << '\n';
}