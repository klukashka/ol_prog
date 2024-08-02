#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;

    
int factorize(ll n){
    int ans = 0, power = 0;
    while (n % 2 == 0){
        power++;
        n /= 2;
    }
    if (power > 0){
        ans = ans ^ power;
        power = 0;
    }
    for (ll i = 3; i*i <= n; i = i + 2){
        while (n % i == 0){
            power++;
            n = n / i;
        }
        if (power > 0){
            ans = ans ^ power;
            power = 0;
        }
    }
    if (n != 1){
        ans = ans ^ 1;
    }
    return ans;
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    int ans = factorize(n);
    if (ans > 0){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}