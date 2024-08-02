#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll MOD = 1000000007;

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
    return power(x, MOD - 2, n);
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

vector<ll> fact(100001, 1);
vector<ll> inv_fact(100001, 1);
void prepare(){
    for (ll i = 2; i <= 100000; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        inv_fact[i] = (inv_fact[i-1] * inverse(i, MOD)) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();
    string s;
    cin >> s;
    set<char> letters(s.begin(), s.end());
    vector<char> letters_v(letters.begin(), letters.end());
    ll result = fact[s.size()];
    for (int i = 0; i < letters_v.size(); i++){
        ll counter = 0;
        for (int j = 0; j < s.size(); j++){
            if (s[j] == letters_v[i]){
                counter++;
            }
        }
        result = (result * inv_fact[counter]) % MOD;
    }
    cout << result << '\n';
}