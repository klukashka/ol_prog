#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct pair_{
    ll left, right, value;
};

bool compare(pair_ a, pair_ b){
    if (a.left < b.left){
        return true;
    } else {
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> p(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll sm = v[0];
    for (int i = 1; i < n; i++){
        ll mx = v[i];
        sm += mx;
        for (int j = i - 1; j >= 0; j--){
            if (v[j] > mx){
                mx = v[j];
            }
            sm += mx;
        }
    }
    cout << sm << '\n';
}