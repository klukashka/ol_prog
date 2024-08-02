#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
#define all(x) begin(x), end(x)

bool check_good(int m1, int m2, int m){
    for (int i = 0; i < m; i++){
        if ((m1 & 1 << i) != 0 && (m2 & 1 << i) == 0){
            m1 = m1 ^ (1 << i);
            m2 = m2 ^ (1 << i);
        }
    }
    if (m2 != (1 << m) - 1){
        return false;
    }
    for (int i = 0; i < m-1; i++){
        if ((m1 & 3) == 3){
            m1 = m1 ^ 3;
            m1 = m1 >> 1;
            i++;
        } else {
            if ((m1 & 3) == 1){
                return false;
            }
            m1 = m1 >> 1;
        }
    }
    return m1 == 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    const int max_m = 1 << m;
    vector<vector<int>> good(max_m, vector<int>(max_m));
    for (int m1 = 0; m1 < max_m; m1++){
        for (int m2 = 0; m2 < max_m; m2++){
            good[m1][m2] = check_good(m1, m2, m);
        }
    }
    vector<ll> dp_old(max_m, 1);
    vector<ll> dp_new(max_m);
    for (int i = 1; i < n; i++){
        dp_new.assign(max_m, 0);
        for (int m1 = 0; m1 < max_m; m1++){
            for (int m2 = 0; m2 < max_m; m2++){
                dp_new[m1] = (dp_new[m1] + dp_old[m2] * good[m2][m1]) % mod;
            }
        }
        swap(dp_old, dp_new);
    }
    ll ans = 0;
    for (ll el : dp_old){
        ans = (ans + el) % mod;
    }
    cout << ans << '\n';
}