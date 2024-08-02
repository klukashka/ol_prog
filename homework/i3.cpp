#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1000000000;

int solve(int l, int r, vector<vector<int>> &dp, const vector<int> &rows, const vector<int> &cols){
    if (dp[l][r] != -1){
        return dp[l][r];
    }
    int res = inf;
    for (int k = l + 1; k <= r; k++){
        res = min(res, solve(l, k - 1, dp, rows, cols) + solve(k, r, dp, rows, cols) + rows[l-1] * rows[k-1] * cols[r-1]);
    }
    dp[l][r] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> rows(n), cols(n);
    for (int i = 0; i < n; i++){
        cin >> rows[i] >> cols[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }
    cout << solve(1, n, dp, rows, cols) << '\n';
}