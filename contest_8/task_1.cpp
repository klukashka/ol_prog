#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct pair_{
    ll left, right, value;
};

bool compare(pair_ a, pair_ b){
    if (a.left < b.left){
        return true;
    } else if (a.left == b.left){
        if (a.right < b.right){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair_> v(n);
    for (int i = 0; i < q; i++){
        cin >> v[i].left >> v[i].right >> v[i].value;
    }
    sort(v.begin(), v.end(), compare);
    pair_ p = v[0];
    for (int i = 1; i < n; i++){
        if (v[i].left > p.right){
            for (int j = p.left; j <= p.right; j++){
                cout << p.value << " ";
            }
            p = v[i];
        } else if (v[i].left <= p.right){
            for (int j = p.left; j < v[i].left; j++){
                cout << p.value << " ";
            }
            p.left = v[i].left;
            p.right = v[i].right;
            p.value = p.value + v[i].value;
        }
    }
    cout << '\n';
}