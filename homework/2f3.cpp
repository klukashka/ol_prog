#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6;
const int P = 31;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> pows(N + 1, 1);
    for (int i = 1; i <= N; i++){
        pows[i] = (pows[i-1] * P) % MOD;
    }
    string p, t;
    cin >> p >> t;
    int m = p.size();
    int n = t.size();
    ll hp = 0;
    for (int i = 0; i < m; i++){
        hp = (hp * P + p[i] - 'a' + 1) % MOD;
    }
    vector<ll> pref(n+1);
    for (int i = 1; i <= n; i++){
        pref[i] = (pref[i-1] * P + t[i-1] - 'a' + 1) % MOD;
    }
    int ans = 0;
    for (int i = m; i <= n; i++){
        ll subh = (pref[i] - pref[i - m] * pows[m]) % MOD;
        if (subh < 0){
            subh += MOD;
        }
        if (subh == hp){
            ans++;
        }
    }
    cout << ans << '\n';
}