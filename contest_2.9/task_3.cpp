#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
int const N = 1e5;
template <class T>
    
struct segtree{
    int n;
    vector<T> data;
    
    T f(const T& x, const T& y){return x+y;}
    
    segtree(int sz) : n(sz), data(4*n + 1, 0) {}
    
    segtree(const vector<T>& a) : segtree(a.size()) {build(0, 0, n, a);}
    
    void build(int id, int lo, int hi, const vector<T>& a){
        if (lo + 1 == hi){
            data[id] = a[lo];
            return;
        }
        int mid = (lo+hi)/2;
        build(2*id+1, lo, mid, a);
        build(2*id+2, mid, hi, a);
        data[id] = f(data[id*2+1], data[id*2+2]);
    }

    T get(int l, int r){
        return get(0, 0, n, l, r);
    }
    T get(int id, int lo, int hi, int l, int r){
        if (r <= lo || hi <= l){
            return T();
        }
        if (l <= lo && hi <= r){
            return data[id];
        }
        int mid = (lo + hi)/2;
        return f(get(2*id+1, lo, mid, l, r), get(2*id+2, mid, hi, l, r));
    }
    
    void set(int p, const T& x){
        set(0, 0, n, p, -p);
        set(0, 0, n, x, x);
    }
    
    void set(int id, int lo, int hi, int p, int x){
        if (lo + 1 == hi){
            data[id] += x;
            return;
        }
        int mid = (lo + hi) / 2;
        if (p < mid){
            set(2*id + 1, lo, mid, p, x);
        } else {
            set(2*id + 2, mid, hi, p, x);
        }
        data[id] = f(data[2*id + 1], data[2*id + 2]);
    }
};
    
    
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), cnt(N + 1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]] += a[i];
    }
    segtree<ll> tr(cnt);

    int k;
    cin >> k;
    int q, x, y;
    for (int i = 0; i < k; i++){
        cin >> q >> x >> y;
        if (q == 0){
            cout << tr.get(x, ++y) << '\n';
        } else if (q == 1){
            tr.set(a[x-1], y);
            a[x-1] = y;
        }
    }
}