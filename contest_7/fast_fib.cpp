#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;


vector<vector<ll>> mat_mult(vector<vector<ll>> m1, vector<vector<ll>> m2){
    vector<vector<ll>> res(m1.size(), vector<ll>(m2[0].size()));
    for (int i = 0; i < m1.size(); i++){
        for (int j = 0; j < m2[0].size(); j++){
            ll sm = 0;
            for (int k = 0; k < m2.size(); k++){
                sm = (sm + (m1[i][k] * m2[k][j]) % MOD) % MOD;
            }
            res[i][j] = sm;
        }
    }
    return res;
}

vector<ll> mat_vec_mult(vector<vector<ll>> m, vector<ll> v){
    vector<ll> res(m.size());
    for (int i = 0; i < m.size(); i++){
        ll sm = 0;
        for (int j = 0; j < v.size(); j++){
            sm = (sm + (m[i][j] * v[j]) % MOD) % MOD;
        }
        res[i] = sm;
    }
    return res;
}


vector<ll> mat_power(vector<vector<ll>> a, ll p){
    vector<ll> res{1, 0};
    while (p > 0){
        if (p % 2 == 1){
            res = mat_vec_mult(a, res);
        }
        p = p / 2;
        a = mat_mult(a, a);
    }
    return res;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t, n;
    cin >> t;
    while (t--){
        cin >> n;
        vector<vector<ll>> A{{1, 1}, {1, 0}};
        vector<ll> res_vec = mat_power(A, n - 1);
        cout << res_vec[0] << '\n';
    }
}