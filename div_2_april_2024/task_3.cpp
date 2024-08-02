#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
vector<ll> dp(3e5 + 5);


void solve(){
    int n, k, left;
    cin >> n >> k;
    left = n; // how many rows and columns left
    int x, y;
    if (k > 0){
        for (int i = 0; i < k; i++){
            cin >> x >> y;
            if (x == y){
                left--;
            } else {
                left -= 2;
            }
        }
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= left; i++){
        dp[i] = (dp[i-1] + (2*(i-1)*dp[i-2]) % MOD) % MOD;
    }
    cout << dp[left] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}