#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

int f(vector<vector<int>> &c, int n, int m){
    vector<int> dp_curr(m+1, 0);
    vector<int> dp_prev(m+1, 0); 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp_curr[j] = dp_prev[j];
            for (int k = 0; k <= j; k++){
                dp_curr[j] = max(c[i][k] + dp_prev[j-k], dp_curr[j]);
            }
        }
        swap(dp_curr, dp_prev);
    }
    return dp_prev[m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> c[i][j];
            }
        }
        cout << f(c, n, m) << '\n';
    }
}