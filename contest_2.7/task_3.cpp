#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1e9;
#define all(x) begin(x), end(x)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<short>> c(n, vector<short>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    ll ans = 0;
    for (int first = 0; first < n; first++){
        vector<vector<ll>> dp(1 << n, vector<ll>(n));
        dp[1 << first][first] = 1;
        for (int mask = 2; mask < (1 << n); mask++){
            for (int i = 0; i < n; i++){
                if (!(mask & (1 << i))){
                    continue;
                }
                int nmask = mask ^ (1 << i);
                for (int j = 0; j < n; j++){
                    if (!c[j][i] || !(mask & (1 << j))){
                        continue;
                    }
                    dp[mask][i] += dp[nmask][j];
                }
            }
        }
        for (int i = 0; i < n; i++){
            ans += dp[(1 << n) - 1][i];
        }
    }
    cout << ans << '\n';
}