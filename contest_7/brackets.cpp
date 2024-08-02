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

ll c(ll n, ll k, vector<ll> &f){
    ll res = (((f[n] * inverse(f[n - k])) % MOD) * inverse(f[k])) % MOD;
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll p = MOD - 2;
    while (p > 0){
        mod_powering.push_back(p % 2);
        p = p / 2;
    }

    string s;
    cin >> s;
    ll cnt0 = 0, cnt1 = 0;
    for (ll i = 0; i < s.size(); i++){
        if (s[i] == '('){
            cnt0++;
        } else {
            cnt1++;
        }
    }
    vector<ll> fact(200001, 1);
    for (ll i = 1; i <= 200000; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll sm = 0;
    ll mn = min(cnt0, cnt1);
    for (ll i = 1; i <= mn; i++){
        sm = (sm + (c(cnt1, i, fact) * c(cnt0, i, fact)) % MOD) % MOD;
    }
    cout << sm << '\n';
}