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

ll fact(ll a){
    ll res = 1;
    for (ll i = a; i > 1; i--){
        res = (res * i) % MOD;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll result = fact(n);
    result = (result * inverse(2 * n)) % MOD;
    cout << result << '\n';
}