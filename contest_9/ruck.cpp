#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
ll inf = 5000000000000000000;

ll f(vector<ll> &m, vector<short> &c, ll &w, ll &n, int &sm){
    vector<ll> curr(sm + 1, inf);
    vector<ll> prev(sm + 1, inf);
    prev[c[0]] = m[0];

    for (int i = 1; i < n; i++){
        for (int j = 0; j < c[i]; j++){
            curr[j] = prev[j];
        }
        curr[c[i]] = m[i];
        for (int j = c[i] + 1; j <= sm; j++){
            curr[j] = min(prev[j], prev[j-c[i]] + m[i]);
        }
        swap(curr, prev);
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < 26; j++){
    //         if (dp[i][j] == inf){
    //             cout << "inf" << ' ';
    //         } else {
    //             cout << dp[i][j] << ' ';
    //         }
    //     }
    //     cout << "end\n";
    // }
    int mn_ind = 0;
    for (int j = 0; j <= sm; j++){
        if (w >= prev[j]){
            mn_ind = j;
        }
    }
    return mn_ind;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, w;
    cin >> n >> w;
    vector<ll> m(n);
    vector<short> c(n);
    int sm = 0;
    for (int i = 0; i < n; i++){
        cin >> m[i] >> c[i];
        sm += c[i];
    }
    cout << f(m, c, w, n, sm) << '\n';
}