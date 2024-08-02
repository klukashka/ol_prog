#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18;
struct item{
    int to, from, w;
};
using pll = pair<ll, int>;


int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int t;
    cin >> t;
    vector<vector<int>> ans(t, vector<int>());
    for (int p = 0; p < t; p++){
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        vector<int> city(k);
        for (int i = 0; i < k; i++){
            cin >> city[i];
            city[i]--;
        }
        vector<vector<item>> g(n);
        for (int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            g[v].push_back({v, u, w});
            // g[v].push_back({v, u, w});
        }
        set<int> good_city;
        vector<ll> dp(n, inf);
        vector<bool> been_there(n, false);
        priority_queue<pll, vector<pll>, greater<pll>> q;
        for (int c : city){
            dp[c] = 0;
            q.push({dp[c], c});
        }
        while (q.size()){
            pll cur = q.top();
            int u = cur.second;
            q.pop();
            if (been_there[u]){
                continue;
            }
            been_there[u] = true;
            for (item edge : g[u]){
                // for (int i = 0; i < n; i++){
                //     cout << dp[i] << ' ';
                // }
                // cout << '\n';
                if (dp[edge.to] + edge.w < dp[edge.from]){
                    dp[edge.from] = dp[edge.to] + edge.w;
                    q.push({dp[edge.from], edge.from});
                    // if (edge.to == 9){
                    //     cout << "\n||| " << u + 1 << " u w "<<edge.w << "   " << dp[edge.to] << "   \n";
                    // }
                }
            }
        }
        for (int u = 0; u < n; u++){
            if (dp[u] <= d){
                good_city.insert(u + 1);
            }
        }
        // cout << "\nbeg ";
        for (int s : good_city){
            cout << s << ' ';
        }
        cout << '\n';
        // cout << "all\n";
        // for (int s : good_city){
        //     ans[p].push_back(s);
        // }
        // cout << '\n';
        // for (int i = 0; i < n; i++){
        //     cout << dp[i] << ' ';
        // }
        // cout << '\n' << '\n';
        
    }
    // cout << '\n'; 
    // for (int i = 0; i < t; i++){
    //     for (int v : ans[i]){
    //         cout << v << ' ';
    //     }
    //     cout << '\n';
    // }
}