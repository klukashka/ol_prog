#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct pair_{
    ll left, right;
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
    vector<pair_> v(n);
    vector<ll> p;
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> v[i].left >> v[i].right;
    }
    sort(v.begin(), v.end(), compare);
    // p.emplace_back(v[0].left, v[0].right);
    // for (int i = 1; i < n; i++){
    //     for (int j = 0; j < p.size(); j++){
    //         if 
    //     }
    // }
    ll sm = 0;
    pair_ segment = v[0];
    for (int i = 1; i < n; i++){
        if (v[i].left <= segment.right && v[i].right > segment.right){
            segment.right = v[i].right;
        } else if (v[i].left > segment.right){
            sm += segment.right - segment.left + 1;
            segment = v[i];
        }
    }
    sm += segment.right - segment.left + 1;
    cout << sm << '\n';
}