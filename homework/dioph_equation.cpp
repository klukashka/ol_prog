#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MOD = 1000000007;

ll help_gcd(ll a, ll b, ll &x, ll&y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll g = help_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y;
    ll g = help_gcd(a, b, x, y);
    if (c % g > 0){
        cout << -1 << '\n';
        return;
    }
    ll d = c / g;
    x *= d;
    y *= d;
    cout << g << " " << x << " " << y << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t > 0){
        solve();
        t--;
    }
}