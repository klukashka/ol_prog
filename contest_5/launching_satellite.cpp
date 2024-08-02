#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long int;

ll mcd(ll a, ll b){
    while (a != b){
        if (a > b){
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, res;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    res = v[0];
    for (int i = 1; i < n; i++){
        res = v[i] / mcd(res, v[i]) * res;
    }
    cout << res << endl;
}