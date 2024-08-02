#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    if (2 * a > b){
        cout << (n / 2) * b + (n % 2) * a << '\n';
    } else {
        cout << n * a << '\n';
    }
}