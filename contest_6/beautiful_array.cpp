#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

bool no_same_digits(int a, int b){
    vector<int> va;
    vector<int> vb;
    while (a > 0){
        va.push_back(a % 10);
        a /= 10;
    }
    while (b > 0){
        vb.push_back(b % 10);
        b /= 10;
    }
    for (int i = 0; i < va.size(); i++){
        for (int j = 0; j < vb.size(); j++){
            if (va[i] == vb[j]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int MOD = 1000000007;
    int n, k;
    cin >> n >> k;
    vector<vector<bool>> c(k+1, vector<bool>(k+1, 0));
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= k; j++){
            if (no_same_digits(i, j)){
                c[i][j] = 1;
                c[j][i] = 1;
            }
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    for (int i = 1; i <= k; i++){
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= k; j++){
            for (int l = 1; l <= k; l++){
                dp[i][j] = (dp[i][j] + dp[i-1][l] * c[j][l]) % MOD;
            }
        }
    }

    int sm = 0;
    for (int i = 1; i <= k; i++){
        sm = (sm + dp[n][i]) % MOD;
    }

    cout << sm << '\n';
}