#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;

vector<ll> mod_powering;
    
ll power(ll a){
    ll res = 1;
    for (int i = 0; i < mod_powering.size(); i++){
        if (mod_powering[i]){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return res;
}

ll inverse(ll x){
    return power(x);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    if (n >= k){
        ll p = MOD - 2;
        while (p > 0){
            mod_powering.push_back(p % 2);
            p = p / 2;
        }
        vector<ll> fact(101, 1);
        for (int i = 1; i <= 100; i++){
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        ll inv = inverse(fact[n - k]);
        ll res = (((((fact[n] * fact[n]) % MOD) * ((inv * inv) % MOD)) % MOD) * inverse(fact[k])) % MOD;
        cout << res << '\n';
    } else {
        cout << 0 << '\n';
    }
}