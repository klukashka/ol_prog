#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long int;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int k;
    cin >> n >> m >> k;
    n++;
    m++;
    vector<vector<ll>> res(n, vector<ll>(m, 0));
    for (int i = 0; i < k; i++){
        int ii , jj;
        cin >> ii >> jj;
        res[ii][jj] = -1;
    }
    if (res[0][0] != -1 && res[n-1][m-1] != -1){
        res[0][0] = 1;
        for (short i = 1; i < n; i++){
            if (res[i][0] != -1 && res[i-1][0] != -1){
                res[i][0] = 1;
            } else {
                res[i][0] = -1;
            }
        }

        for (short i = 1; i < m; i++){
            if (res[0][i] != -1 && res[0][i-1] != -1){
                res[0][i] = 1;
            } else {
                res[0][i] = -1;
            }
        }
        for (short i = 1; i < n; i++){
            for (short j = 1; j < m; j++){
                if (res[i][j] != -1){
                    if (res[i-1][j] == -1){
                        if (res[i][j-1] == -1){
                            res[i][j] == -1;
                        } else {
                            res[i][j] = (res[i][j] + res[i][j-1]) % 1000000007;
                        }
                    } else {
                        if (res[i][j-1] == -1){
                            res[i][j] = (res[i][j] + res[i-1][j]) % 1000000007;
                        } else {
                            res[i][j] = ((res[i][j] + res[i][j-1]) % 1000000007 + res[i-1][j]) % 1000000007;
                        }
                    }
                }
            }
        }
        if (res[n-1][m-1] > 0){
            cout << res[n-1][m-1] % 1000000007 << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else {
        cout << 0 << '\n';
    }
}