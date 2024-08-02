#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
template <class T>

struct segtree{
    int n;
    vector<T> data;

    T f(const T& x, const T& y){return x+y;}

    segtree(int sz) : n(sz), data(4*n) {}

    segtree(const vector<T>& a) : segtree(a.size()) {build(0, 0, n, a);}

    void build(int id, int lo, int hi, const vector<T>& a){
        if (lo + 1 == hi){
            data[id] = a[lo];
            return;
        }
        int mid = (lo+hi)/2;
        build(2*id+1, lo, mid, a);
        build(2*id+2, mid, hi, a);
    }

    void add(int l, int r, int x){
        add(0, 0, n, l, r, x);
    }
    void add(int id, int lo, int hi, int l, int r, const int& x){
        if (r <= lo || hi <= l){
            return;
        }
        if (l <= lo && hi <= r){
            data[id] += x;
            return;
        }
        int mid = (lo + hi)/2;
        add(2*id+1, lo, mid, l, r, x);
        add(2*id+2, mid, hi, l, r, x);
    }

    T get(int l, int r){
        return get(0, 0, n, l, r);
    }
    T get(int id, int lo, int hi, int l, int r){
        if (lo + 1 == hi){
            return data[id];
        }
        int mid = (lo + hi)/2;
        if (l < mid){
            return data[id] + get(id*2+1, lo, mid, l, r);
        } else {
            return data[id] + get(id*2+2, mid, hi, l, r);
        }
    }
};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    segtree<ll> tr(a);
    // cout << "built\n";
    // for (int i = 0; i < tr.data.size(); i++){
    //     cout << tr.data[i] << ' ';
    // } cout << '\n';
    int k;
    cin >> k;
    int q;
    for (int i = 0; i < k; i++){
        cin >> q;
        if (q == 0){
            int p;
            cin >> p;
            p--;
            cout << tr.get(p, p+1) << '\n';
        } else if (q == 1){
            int l, r, x;
            cin >> l >> r >> x;
            l--;r--;
            tr.add(l, r+1, x);
        }
        // for (int i = 0; i < tr.data.size(); i++){
        //     cout << tr.data[i] << ' ';
        // } cout << '\n';
    }
}
