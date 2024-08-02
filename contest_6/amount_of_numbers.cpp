#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int MOD = 1000000007;
    vector<vector<ll>> dp(101, vector<ll>(1001, 0));
    for (int i = 1; i < 10; i++){
        dp[1][i] = 1;
    }
    for (int i = 2; i <= 100; i++){
        //dp[i][0] = 0;
        for (int k = 1; k <= 9; k++){
            for (int j = 0; j <= k; j++){
                dp[i][k] = (dp[i][k] + dp[i-1][j]) % MOD;
            }
        }
        for (int k = 10; k <= 1000; k++){
            for (int j = 0; j <= 9; j++){
                dp[i][k] = (dp[i][k] + dp[i-1][k - j]) % MOD;
            }
        }
    }
    dp[1][0] = 1;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, s;
        cin >> n >> s;
        int sm = 0;
        for (int j = 1; j <= n; j++){
            sm = (sm + dp[j][s]) % MOD;
        }
        cout << sm << '\n';
    }
}