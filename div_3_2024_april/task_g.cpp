#include <bits/stdc++.h>
    
using namespace std;
using ll = long long int;
    
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }
        int ans = __gcd(v[0][0], v[n-1][m-1]);
        vector<int> divisors;
        for (int i = 1; i * i <= ans; i++){
            if (ans % i == 0){
                divisors.push_back(i);
                divisors.push_back(ans / i);
            }
        }
        sort(divisors.begin(), divisors.end());
        int mx = 1;
        for (int divisor : divisors){
            vector<vector<int>> if_div(n, vector<int>(m, 0));
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (v[i][j] % divisor == 0){
                        if_div[i][j] = 1;
                    }
                }
            }
            for (int i = 1; i < n; i++){
                if_div[i][0] = if_div[i][0] + if_div[i-1][0];
            }
            for (int i = 1; i < m; i++){
                if_div[0][i] = if_div[0][i] + if_div[0][i-1];
            }
            for (int i = 1; i < n; i++){
                for (int j = 1; j < m; j++){
                    if_div[i][j] = max(if_div[i][j-1], if_div[i-1][j]) + if_div[i][j];
                }
            }
            if (if_div[n-1][m-1] == n + m - 1){
                mx = divisor;
            }
        }
        cout << mx << '\n';
    }
}