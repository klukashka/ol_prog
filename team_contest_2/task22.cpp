#include <bits/stdc++.h>
    
using namespace std;
using pii = pair<int, int>;

struct item{
    int cd1, cd2, summa;
};

item mn(item constant, item prev, int c, int which){
    if (constant.summa > prev.summa + c){
        return constant;
    } else if (constant.summa == prev.summa + c){
        if (abs(constant.cd1 - constant.cd2) < abs(prev.cd1 - prev.cd2)){
            return constant;
        } else {
            if (which == 0){
                prev.cd1 += c;
                prev.summa += c;
                return prev;
            } else {
                prev.cd2 += c;
                prev.summa += c;
                return prev;
            }
        }
    } else {
        if (which == 0){
                prev.cd1 += c;
                prev.summa += c;
                return prev;
            } else {
                prev.cd2 += c;
                prev.summa += c;
                return prev;
            }
    }
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
        for (int j = 0; j <= i; j++){
            for (int k = 0; k <= i; k++){
                for (int p = 0; p <= i; p++){
                    if (j + k + p == i){
                        if (check(dp[j][k][p], minutes[i], c) == 2){
                            dp[j][k+1][p] = mn(dp[j][k+1][p], dp[j][k][p] ,minutes[i], 1);
                            dp[j+1][k][p] = mn(dp[j+1][k][p], dp[j][k][p] ,minutes[i], 0);

                            dp[j][k][p+1] = dp[j][k][p];

                        } else if (check(dp[j][k][p], minutes[i], c) == 1){
                            dp[j+1][k][p] = dp[j][k][p];

                            dp[j][k+1][p] = mn(dp[j][k+1][p], dp[j][k][p] ,minutes[i], 1);

                            dp[j][k][p+1] = dp[j][k][p];

                        } else if (check(dp[j][k][p], minutes[i], c) == 0){
                            dp[j+1][k][p] = mn(dp[j+1][k][p], dp[j][k][p] ,minutes[i], 0);

                            dp[j][k+1][p] = dp[j][k][p];

                            dp[j][k][p+1] = dp[j][k][p];

                        } else {
                            dp[j+1][k][p] = dp[j][k][p];
                            dp[j][k+1][p] = dp[j][k][p];
                            dp[j][k][p+1] = dp[j][k][p];
                        }
                        //cout << minutes[i] << ' ' << dp[i+1][j][k].cd1 << ' ' << dp[i+1][j][k].cd2 << '\n';
                    }
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