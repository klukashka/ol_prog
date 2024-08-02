#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;

ll mod(ll a, ll md){
    if (a >= 0){
        return a % md;
    } else {
        return (md + a) % md;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> dp(n + 1);
    if (n > k){
        dp[0] = 1;
        ll sm = 1;
        for (int i = 1; i <= k; i++){
            dp[i] = sm;
            sm = (2 * sm) % MOD;
        }
        for (int i = k + 1; i < n + 1; i++){
            dp[i] = mod((sm - dp[i - k - 1]), MOD);
            sm = mod((sm + dp[i] - dp[i - k - 1]), MOD);
        }
        cout << dp[n] << endl;
    } else {
        ll sm = 1;
        for (int i = 1; i < n; i++){
            sm = mod((2 * sm), MOD);
        }
        cout << sm << endl;
    }
}