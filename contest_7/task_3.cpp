#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll MOD = 1000000007;

ll power(ll a, ll p){
    ll res = 1;
    while (p > 0){
        if (p % 2 == 1){
            res = (res * a) % MOD;
        }
        p = p / 2;
        a = (a * a) % MOD;
    }
    return res;
}



ll inverse(ll x){
    return power(x, MOD - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll b1, q, n;
        cin >> b1 >> q >> n;
        //cout << (inverse(q - 1)) % MOD << " inversed to " << q - 1 << '\n';
        if (q != 1){
            ll sm = ((b1 * (power(q, n) - 1)) % MOD) * (inverse(q - 1)) % MOD;
            cout << sm << '\n';
        } else {
            ll sm = (b1 * n) % MOD;
            cout << sm << '\n';
        }
    }
}