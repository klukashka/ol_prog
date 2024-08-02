#include <iostream>
#include <vector>
    
using namespace std;
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<vector<int>>> dp(201, vector<vector<int>>(201, vector<int>(201, 0)));
    for (int i = 0; i <= 200; i++){
        for (int j = 0; j <= 200; j++){
            for (int k = 0; k <= 200; k++){
                dp[i][j][k] = max(max(dp[max(0, i-1)][j][k], dp[i][max(j-1, 0)][k]), dp[i][j][max(k-1, 0)]);
                int val = (((((i)&1)*1) ^ (((j)&1)*2) ^ (((k)&1)*3)) == 0);
                dp[i][j][k] += val;
                dp[0][0][0] = 0;
            }
        }
    }

    int n; 
    cin >> n;
    while (n--){
        vector<int> c(5, 0);
        cin >> c[1] >> c[2] >> c[3] >> c[4];
        int ans = c[4] / 2;
        cout << dp[c[1]][c[2]][c[3]] + ans << '\n';
    }
}