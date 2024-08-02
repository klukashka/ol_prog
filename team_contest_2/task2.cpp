#include <bits/stdc++.h>
    
using namespace std;
using pii = pair<int, int>;

struct item{
    int cd1, cd2, summa;
};

item mx(item a, item b){
    if (a.summa > b.summa){
        return a;
    }
    return b;
}

int check(item a, int m, int c){
    if (a.cd1 + m <= c){
        if (a.cd2 + m <= c){
            return 2;
        } else {
            return 0;
        }
    } else if (a.cd2 + m <= c){
        return 1;
    } else {
        return -1;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, n;
    cin >> c >> n;
    vector<int> minutes(n);
    for (int i = 0; i < n; i++){
        cin >> minutes[i];
    }
    sort(minutes.begin(), minutes.end(), greater<int>());
    vector<vector<vector<item>>> dp(n + 1, vector<vector<item>>(n + 1, vector<item>(n + 1, {0, 0, 0})));
    for (int i = 0; i < n; i++){
        for (int j = i; j <= n; j++){
            for (int k = i; k <= n; k++){
                for (int p = i; p <= n; p++){
                    if (check(dp[j][k][p], minutes[i], c) == 2){
                        dp[j][k+1][p] = dp[j][k][p];
                        dp[j][k+1][p].cd2 += minutes[i];
                        dp[j][k+1][p].summa += minutes[i];

                        dp[j+1][k][p] = dp[j][k][p];
                        dp[j+1][k][p].cd1 += minutes[i];
                        dp[j+1][k][p].summa += minutes[i];

                        dp[j][k][p] = dp[j][k][p];

                    } else if (check(dp[j][k][p], minutes[i], c) == 1){
                        dp[j][k+1][p] = dp[j][k][p];
                        dp[j][k+1][p].cd2 += minutes[i];
                        dp[j][k+1][p].summa += minutes[i];

                        dp[j][k][p+1] = dp[j][k][p];

                    } else if (check(dp[j][k][p], minutes[i], c) == 0){
                        dp[j+1][k][p] = dp[j][k][p];
                        dp[j+1][k][p].cd1 += minutes[i];
                        dp[j+1][k][p].summa += minutes[i];

                        dp[j][k][p+1] = dp[j][k][p];

                    } else {
                        dp[j][k][p+1] = dp[j][k][p];

                    }
                    //cout << minutes[i] << ' ' << dp[i+1][j][k].cd1 << ' ' << dp[i+1][j][k].cd2 << '\n';
                }
            }
        }
    }
    item ans = dp[0][0][0];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            for (int k=0; k <= n; k++){
                if (dp[i][j][k].summa > ans.summa){
                    ans = dp[i][j][k];
                } else if (dp[i][j][k].summa == ans.summa){
                    if (abs(dp[i][j][k].cd1 - dp[i][j][k].cd2) < abs(ans.cd1 - ans.cd2)){
                        ans = dp[i][j][k];
                    }
                }
            }
        }
    }
    // for (int i = 0; i <= n; i++){
    //     for (int j = 0; j <= n; j++){
    //         for (int k=0; k <= n; k++){
    //             cout << dp[i][j][k].cd1 << ' ' << dp[i][j][k].cd2 << '|';
    //         }
    //         cout << '\n';
    //     }
    //     cout << "||||||\n";
    // }

    if (ans.cd1 > ans.cd2){
        cout << ans.cd1 << ' ' << ans.cd2 << '\n';
    } else {
        cout << ans.cd2 << ' ' << ans.cd1 << '\n';
    }
}