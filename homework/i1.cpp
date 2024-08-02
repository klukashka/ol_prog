#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

int LCS(string s1, string s2){
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 1; i <= s1.size(); i++){
        for (int j = 1; j <= s2.size(); j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;
    cout << LCS(str1, str2) << '\n';

}