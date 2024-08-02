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

    ll n;
    cin >> n;
    vector<int> dims(n, 0);
    for (int i = 0; i < n; i++){
        cin >> dims[i];
    }
    ll sm = 0;
    ll mx_dims = 0;
    for (ll i = 0; i < dims.size(); i++){
        sm += dims[i];
        if (dims[i] > mx_dims){
            mx_dims = dims[i];
        }
    }
    vector<ll> fact(sm + 1, 1);
    for (ll i = 2; i <= sm; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll res = fact[sm];
    for (int i = 0; i < dims.size(); i++){
        res = (res * inverse(fact[dims[i]])) % MOD;
    }
    cout << res << '\n';
}