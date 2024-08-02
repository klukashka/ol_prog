#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> p(n + 1);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    p[0] = 0;
    p[1] = v[0];
    for (int i = 2; i <= n; i++){
        p[i] = v[i - 1] + p[i-1];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] << '\n';
    }
}