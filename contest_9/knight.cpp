#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int mx_dim = 2 * max(n, m);
    vector<vector<int>> a(mx_dim + 1, vector<int>(mx_dim, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(mx_dim + 1, vector<int>(mx_dim + 1, -1));
    dp[0][0] = 0;
    for (int y = 1; y <= mx_dim; y++){
        for (int x = 0; x <= y; x++){
            int i = y - x;
            int j = x;
            if (i < n && j < m){
                if ((i - 2) >= 0 && (j + 1) <= mx_dim){
                    if (dp[i-2][j+1] != -1){
                        dp[i][j] = 0;
                    }
                }
                if ((i - 2) >= 0 && (j - 1) >= 0){
                    if (dp[i-2][j-1] != -1){
                        dp[i][j] = 0;
                    }
                }
                if ((i - 1) >= 0 && (j - 2) >= 0){
                    if (dp[i-1][j-2] != -1){
                        dp[i][j] = 0;
                    }
                }
                if ((i + 1) >= 0 && (j - 2) >= 0){
                    if (dp[i+1][j-2] != -1){
                        dp[i][j] = 0;
                    }
                }
            }
        }
    }

    // for (int i = 0; i <= mx_dim; i++){
    //     for (int j = 0; j <= mx_dim; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    dp[0][0] = a[0][0];
    for (int y = 1; y <= mx_dim; y++){
        for (int x = 0; x <= y; x++){
            int i = y - x;
            int j = x;
            if (dp[i][j] != -1 && i < n && j < m){
                bool flag = false;
                if ((i - 2) >= 0 && (j + 1) <= mx_dim){
                    if (dp[i-2][j+1] != -1){
                        flag = true;
                        dp[i][j] = max(dp[i][j], dp[i-2][j+1]);
                    }
                }
                if ((i - 2) >= 0 && (j - 1) >= 0){
                    if (dp[i-2][j-1] != -1){
                        flag = true;
                        dp[i][j] = max(dp[i][j], dp[i-2][j-1]);
                    }
                }
                if ((i - 1) >= 0 && (j - 2) >= 0){
                    if (dp[i-1][j-2] != -1){
                        flag = true;
                        dp[i][j] = max(dp[i][j], dp[i-1][j-2]);
                    }
                }
                if ((i + 1) <= mx_dim && (j - 2) >= 0){
                    if (dp[i+1][j-2] != -1){
                        flag = true;
                        dp[i][j] = max(dp[i][j], dp[i+1][j-2]);
                    }
                }
                if (flag){dp[i][j] += a[i][j];}
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mx = max(mx, dp[i][j]);
        }
    }
    // for (int i = 0; i <= mx_dim; i++){
    //     for (int j = 0; j <= mx_dim; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << mx << '\n';
}