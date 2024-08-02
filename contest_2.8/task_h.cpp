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
    int n, m;
    cin >> n >> m;
    int s = max(n, m);
    vector<vector<char>> sg(s+1, vector<char>(s+1));
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
    for (int i = 1; i <= s; i++){
        for (int j = 1; j <= s; j++){
            cout << (int)sg[i][j] << ' ';
        }
        cout << '\n';
    }
    if (sg[n][m] > 0){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}