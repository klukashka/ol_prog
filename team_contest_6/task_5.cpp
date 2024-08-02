#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    ll res = 0;
    for (int i = 0; i < n; i++){
        ll a;
        cin >> a;
        res = res ^ a;
    }
    int counter = 0;
    while (res > 0){
        if (res & 1){
            counter++;
        }
        res = res >> 1;
    }
    cout << counter << '\n';
}