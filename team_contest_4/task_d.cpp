#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll power(ll a, ll p){
    ll res = 1;
    while (p > 0){
        if (p % 2 == 1){
            res = (res * a) % MOD;
        }
        p = p / 2;
        a = (a * a) % MOD;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> dp(n + 1);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++){
        dp[i] = (power(2, i-2) * dp[i-1]) % MOD;
    }
    cout << dp[n] << '\n';
}