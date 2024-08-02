#include <bits/stdc++.h>
    
using namespace std;
    
int mex(const vector<int>& a){
    char n = a.size();
    vector<bool> been(n+1);
    for (int i = 0; i < n; i++){
        if (a[i] <= n){
            been[a[i]] = 1;
        }
    }
    for (int i = 0; i <= n; i++){
        if (!been[i]){
            return i;
        }
    }
    return n;
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int s = 10000;
    vector<vector<char>> sg(10001, vector<char>(10001));
    for (int i = 0; i <= s; i = i + 2){
        sg[i][1] = 1;
        sg[1][i] = 1;
    }
    for (int i = 1; i <= s; i = i + 2){
        sg[i][1] = 0;
        sg[1][i] = 0;
    }
    for (int i = 2; i <= s; i++){
        for (int j = 2; j <= s; j++){
            vector<int> u = {sg[i-1][j], sg[i][j-1], sg[i-1][j-1]};
            sg[i][j] = mex(u);
            sg[j][i] = sg[i][j];
        }
    }
    int ans = 0;
    int n;
    cin >> n;
    while (n--){
        int a, b;
        cin >> a >> b;
        cout << a << ' ' << b << ' ' << (int)sg[a][b] << " f(a, b)\n";
        ans = ans ^ sg[a][b];
        cout << ans << " ans\n";
    }
    if (ans > 0){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}