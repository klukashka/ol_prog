#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long int;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    short n, m;
    cin >> n >> m;
    vector<vector<short>> v(n, vector<short>(m));
    vector<vector<int>> res(n, vector<int>(m));
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    res[0][0] = v[0][0];
    for (short i = 1; i < n; i++){
        res[i][0] = res[i-1][0] + v[i][0];
    }
    for (short i = 1; i < m; i++){
        res[0][i] = res[0][i-1] + v[0][i];
    }
    for (short i = 1; i < n; i++){
        for (short j = 1; j < m; j++){
            res[i][j] = max(res[i][j-1], res[i-1][j]) + v[i][j];
        }
    }
    cout << res[n-1][m-1] << '\n';
}