#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

vector<ll> mod_powering;
vector<ll> fact;
vector<ll> inv_fact;

ll spec_factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = (result * i) % MOD;
	}
	return result % MOD;
}

ll c_is(ll nn, ll kk){
    return ((((fact[nn]) * inv_fact[nn - kk]) % MOD) * inv_fact[kk]) % MOD;
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


ll inverse(ll x, ll n){
    return power(x);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll p = MOD - 2;
    while (p > 0){
        mod_powering.push_back(p % 2);
        p = p / 2;
    }
    ll total_num = (100001);
    // cout << total_num << "total" <<  '\n';
    fact.resize(total_num + 1, 1);
    inv_fact.resize(total_num + 1, 1);

    for (ll i = 2; i <= total_num; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        inv_fact[i] = inverse(fact[i], MOD) % MOD;
    }

    int h, w;
    cin >> h >> w;
    for ()
}