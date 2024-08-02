#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n + 1));
    int a = 1;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= a; j++){
            cin >> v[i][j];
        }
        a++;
    }
    vector<vector<ll>> dp(n, vector<ll>(n + 1, 0));
    dp[0][1] = v[0][1];
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n + 1; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + v[i][j];
        }
    }
    ll mx = 0;
    for (int i = 0; i < n + 1; i++){
        if (dp[n-1][i] > mx){
            mx = dp[n-1][i];
        }
    }
    cout << mx << '\n';
}