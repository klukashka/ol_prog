#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, sm = 0;
    cin >> n;
    ll ind1 = 1, ind2 = n;
    for (ll i = 0; i < n; i++){
        ll num;
        cin >> num;
        sm = sm + num * ind1 * ind2;
        ind1++;
        ind2--;
    }
    cout << sm << '\n';
}