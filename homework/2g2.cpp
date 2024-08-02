#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18;
#define all(x) begin(x), end(x)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    vector<vector<ll>> dp(1 << n, vector<ll>(n, inf));
    dp[1][0] = 0;
    for (int mask = 2; mask < 1 << n; mask++){
        for (int i = 0; i < n; i++){
            if (!(mask & 1 << i)){
                continue;
            }
            int nmask = mask ^ (1 << i);
            for (int j = 0; j < n; j++){
                if (!(mask & 1 << j)){
                    continue;
                }
                dp[mask][i] = min(dp[mask][i], dp[nmask][j] + c[j][i]);
            }
        }
    }
    cout << *min_element(all(dp.back())) << '\n';
}