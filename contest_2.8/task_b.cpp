#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    vector<int> c(5, 0);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        c[a]++;
    }
    int ans = c[4] / 2;
    vector<vector<vector<int>>> dp(112, vector<vector<int>>(112, vector<int>(112, 0)));
    for (int i = 0; i <= 111; i++){
        for (int j = 0; j <= 111; j++){
            for (int k = 0; k <= 111; k++){
                dp[i][j][k] = max(max(dp[max(0, i-1)][j][k], dp[i][max(j-1, 0)][k]), dp[i][j][max(k-1, 0)]);
                int val = (((((i)&1)*1) ^ (((j)&1)*2) ^ (((k)&1)*3)) == 0);
                dp[i][j][k] += val;
                dp[0][0][0] = 0;
            }
        }
    }
    // for (int i = 0; i < 10; i++){
    //     for (int j = 0; j < 10; j++){
    //         for (int k = 0; k < 10; k++){
    //            cout << dp[i][j][k] << "  - " << i << ' ' << j << ' ' << k << '\n';
    //         }
    //     }
    // }
    cout << dp[c[1]][c[2]][c[3]] + ans << '\n';
}