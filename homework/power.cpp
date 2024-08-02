#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MOD = 1000000007;

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
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++){
        ll num, pow;
        cin >> num >> pow;
        ll result = power(num, pow);
        cout << result << '\n';
    }
}