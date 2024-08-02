#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18;
#define all(x) begin(x), end(x)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, kk, k;
    cin >> n >> kk;
    k = n - kk;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    int mx = 0;
    for (int mask = 0; mask < 1 << n; mask++){
        for (int i = 0; i < n; i++){
            if (!(mask & 1 << i)){
                continue;
            }
            int counter = 0;
            int copy_mask = mask;
            while (copy_mask > 0){
                if (copy_mask & 1){
                    counter++;
                }
                copy_mask = copy_mask >> 1;
            }
            if (counter > k){
                continue;
            }
            int nmask = mask ^ (1 << i);
            for (int j = 0; j < n; j++){
                if (!(mask & 1 << j)){
                    continue;
                }
                int val = dp[nmask][j] ^ a[i];
                dp[mask][i] = max(dp[mask][i], val);
                if (counter == k){
                    mx = max(mx, dp[mask][i]);
                }
            }
        }
    }
    // for (int i = 0; i < 1 << n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for (int mask = 0; mask < 1 << n; mask++){
    //     for (int i = 0; i < n; i++){
    //         mx = max(mx, dp[mask][i]);
    //     }
    // }
    cout << mx << '\n';
}