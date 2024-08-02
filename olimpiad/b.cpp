#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll MOD = 998244353;

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


ll inverse(ll x, ll n){
    return power(x);
}

// ll fact(ll a){
//     ll res = 1;
//     for (ll i = a; i > 1; i--){
//         res = (res * i) % MOD;
//     }
//     return res;
// }

// ll inv_fact(ll a){
//     ll res = 1;
//     for (ll i = a; i > 1; i--){
//         res = (res * inverse(i, MOD)) % MOD;
//     }
//     return res;
// }

// vector<ll> fact(N + 1, 1);
// vector<ll> inv_fact(N + 1, 1);
// void prepare(ll N){
//     for (ll i = 2; i <= N; i++){
//         fact[i] = (fact[i-1] * i) % MOD;
//         inv_fact[i] = (inverse(fact[i], MOD)) % MOD;
//     }
// }

vector<ll> fact;
vector<ll> inv_fact;

ll c_is(ll nn, ll kk){
    return ((((fact[nn]) * inv_fact[nn - kk]) % MOD) * inv_fact[kk]) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll p = MOD - 2;
    while (p > 0){
        mod_powering.push_back(p % 2);
        p = p / 2;
    }

    ll n, m;
    cin >> n >> m;
    ll total_num = (n*n - 1) / 2 + 1;
    // cout << total_num << "total" <<  '\n';
    fact.resize(total_num + 1, 1);
    inv_fact.resize(total_num + 1, 1);

    for (ll i = 2; i <= total_num; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        inv_fact[i] = inverse(fact[i], MOD) % MOD;
    }

    ll sum = 0;
    if (total_num > m){
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= m; j++){
                if (i + j <= total_num){
                    sum = (sum + ((c_is(total_num, i) * c_is(total_num - i, j)) % MOD)) % MOD;
                    // cout << sum << " " << i << " " << j << "   " << ((c_is(total_num, i)) * (c_is(total_num - i, j)) % MOD) << '\n';
                }
            }
        }
        
    } else {
        for (int i = 0; i <= total_num; i++){
            for (int j = 0; j <= total_num; j++){
                if (i + j <= total_num){
                    sum = (sum + ((c_is(total_num, i) * c_is(total_num - i, j)) % MOD)) % MOD;
                    // cout << sum << " " << i << " " << j << "   " << ((c_is(total_num, i)) * (c_is(total_num - i, j)) % MOD) << '\n';
                }
            }
        }
        
    }
    cout << sum << '\n';
}
