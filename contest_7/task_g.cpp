#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1000000007;
vector<ll> mod_powering;

ll std_power(ll a, ll p){
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

    ll p = MOD - 2;
    while (p > 0){
        mod_powering.push_back(p % 2);
        p = p / 2;
    }

    int n, k;
    cin >> n >> k;

    vector<ll> fact(2*n + 1, 1);
    for (ll i = 2; i <= 2 * n; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll sigm = 2 * n - k;
    ll ans = fact[sigm] % MOD;
    ans = (ans * inverse(fact[n - k])) % MOD;
    ans = (ans * inverse(fact[n])) % MOD;
    ll two_sigm = std_power(2, sigm);
    ans = (ans * inverse(two_sigm)) % MOD;
    cout << ans << '\n';
}