#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    if (n == 1){
        cout << 0 << '\n';
        return 0;
    }
    ll ans = 1e18;
    vector<int> p(n-1);
    for (int i = 0; i < n-1; i++){
        p[i] = i + 1;
    }
    do{
        ll res = c[0][p[0]];
        for (int i = 1; i < n-1; i++){
            res += c[p[i-1]][p[i]];
        }
        ans = min(ans, res);
    } while (next_permutation(all(p)));
    cout << ans << '\n';
}