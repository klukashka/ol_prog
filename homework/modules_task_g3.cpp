#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll phi(ll n){
    ll res = n;
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            ll alpha = 0;
            while (n % i == 0){
                n = n / i;
                alpha++;
            }
            res -= res / i;
        }
    }
    if (n > 1){
        res -= res / n;
    }
    return res;
}

ll power(ll a, ll p, ll MOD){
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

ll inverse(ll x, ll n){
    return power(x, phi(n) - 1, n);
}

void solve(){
    ll a, m;
    cin >> a >> m;
    a = ((a % m) + m) % m;
    if (__gcd(a, m) == 1){
        cout << inverse(a, m) << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}