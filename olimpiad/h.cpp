#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; i++){
        cin >> a[i];
    }
    int c = 0;
    sort(a.begin(), a.end(), greater<int>());
    vector<vector<int>> ans(n, vector<int>(m));
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            ans[i][j] = a[c];
            c++;
        }
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m - 1; j++){
            cout << ans[i][j] << " ";
        }
        cout << ans[i][m - 1] << '\n';
    }
    for (int j = 0; j < m - 1; j++){
        cout << ans[n - 1][j] << " ";
    }
    cout << ans[n - 1][m - 1];
}