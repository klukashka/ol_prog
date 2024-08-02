#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<char>>;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m;j++){
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j =0; j <= m - 5; j++){
            if (g[i][j] == 'g' && g[i][j+1] == 'r' && g[i][j + 2] == 'a' && g[i][j + 3] == 'p' && g[i][j+4] == 'h'){
                cout << "YES" << '\n';
                return 0;
            }
        }
    }
    for (int j = 0; j < m; j++){
        for (int i =0; i <= n - 5; i++){
            if (g[i][j] == 'g' && g[i+1][j] == 'r' && g[i+2][j] == 'a' && g[i+3][j] == 'p' && g[i+4][j] == 'h'){
                cout << "YES" << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
}