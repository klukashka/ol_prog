#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sm = 0;
    for (int i = 0; i < n; i++){
       cin >> v[i];
       if (v[i] < 0){
        v[i] = MOD + v[i];
       }
    }
    ll pw = power(2, n - 1);
    for (int i = 0; i < n; i++){
        ll num = (pw * v[i]) % MOD;
        sm = (sm + num) % MOD;
    }
    cout << sm << '\n';
}