#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 2e18;

struct edge{
    int from, to;
    ll w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m, s;
    cin >> n >> m >> s;
    vector<edge> g;
    for (int i = 0; i < m; i++){
        int u, v;
        ll weight;
        cin >> u >> v >> weight;
        u--;
        v--;
        g.push_back({u, v, weight});
    }
    vector<ll> dp(n, inf);
    vector<bool> s_conn(n, false);
    s--;
    dp[s] = 0;
    s_conn[s] = true;
    bool flag = true;
    for (int i = 0; i < n && flag; i++){
        flag = false;
        for (edge el : g){
            if (dp[el.from] + el.w < dp[el.to] && s_conn[el.from]){
                flag = true;
                dp[el.to] = dp[el.from] + el.w;
                s_conn[el.to] = true;
            }
        }
    }
    // for (int i = 0; i < n; i++){
    //         if (dp[i] == inf){
    //             cout << "inf ";
    //         } else {
    //             cout << dp[i] << ' ';
    //         }
    // }
    // cout << "\n\n";
    if (flag){
        cout << "Negative cycle\n";
    }
    else {
        for (int i = 0; i < n; i++){
            if (dp[i] > 1e18){
                cout << "inf ";
            } else {
                cout << dp[i] << ' ';
            }
        }
        cout << '\n';
    }
}