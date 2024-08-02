#include <bits/stdc++.h>
    
using ll = long long;
short inf = 10000;
using namespace std;

short mn(short a, short b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    short n;
    cin >> n;
    vector<short> w(n);
    int sm = 0;
    for (short i = 0; i < n; i++){
        cin >> w[i];
        sm += w[i];
    }
    vector<vector<short>> dp(n, vector<short>(2 * sm + 1, inf));
    for (short i = 0; i < n; i++){
        dp[i][sm - w[i]] = 1;
        dp[i][sm + w[i]] = 1;
    }
    for (short i = 1; i < n; i++){
        for (int j = 0; j <= 2 * sm; j++){
            if (dp[i-1][j] != inf){
                dp[i][j - w[i]] = mn(mn(dp[i-1][j - w[i]], dp[i][j - w[i]]), dp[i-1][j] + 1);
                dp[i][j + w[i]] = mn(mn(dp[i-1][j + w[i]], dp[i][j + w[i]]), dp[i-1][j] + 1);
                dp[i][j] = mn(dp[i-1][j], dp[i][j]);
            }
        }
    }

    int ans = dp[n-1][sm];
    if (ans == inf){
        cout << "-1\n"; 
    } else {
        cout << ans << '\n';
    }
}