#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<bool>>& v){
    for (int i = 0; i < v.size(); i++){
        int num = 0;
        int mult = 1;
        for (int j = 29; j >= 0; j--){
            if (v[i][j] == 1){
                num += mult;
            }
            // cout << num << " num\n";
            mult *= 2;
        }
        cout << num << ' ';
    }
    cout << '\n';
}


void error(){
    cout << -1 << '\n';
}

void solve(){
    int n;
    cin >> n;
    vector<vector<bool>> b(n-1, vector<bool>(30));
    for (int i = 0; i < n-1; i++){
        int bb;
        cin >> bb;
        for (int j = 29; j >= 0; j--){
            // cout << bb << " bb\n";
            b[i][j] = bb & 1;
            bb = bb >> 1;
        }
    }
    // print(b);
    vector<vector<bool>> a(n, vector<bool>(30));
    a[0] = b[0];
    for (int i = 1; i < n; i++){
        for (int j = 29; j >= 0; j--){
            if (b[i-1][j] == 1){
                if (a[i-1][j] == 1){
                    a[i][j] = 1;
                } else {
                    error();
                    return ;
                }
            } else {
                if (a[i-1][j] == 1){
                    a[i][j] = 0;
                } else {
                    a[i][j] = 1;
                }
            }
        }
    }
    print(a);
    cout << ((int)5 & (int)1073741822) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}