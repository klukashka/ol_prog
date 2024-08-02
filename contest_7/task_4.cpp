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
    
    ll n, m;
    cin >> n >> m;
    
    ll mx = max(n, m);
    ll mn = min(n, m);

    ll numerator = 1, denominator = 1;
    ll p = MOD - 2;
    
    while (p > 0){
        mod_powering.push_back(p % 2);
        p = p / 2;
    }
    vector<ll> fact(mn + 1, 1);
    for (ll i = 2; i <= mn; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (ll i = mx + 1; i <= n + m; i++){
        numerator = (numerator * i) % MOD;
    }
    denominator = (inverse(fact[mn])) % MOD;
    ll result = (numerator * denominator) % MOD;
    cout << result << '\n';
}