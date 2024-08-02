#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

struct mx{
    int MX, most_left, num;
};

template <class T>
    
struct segtree{
    int n;
    vector<T> data;
    
    T f(const T& x, const T& y){
        if (x.MX > y.MX){
            return x;
        } else if (x.MX < y.MX){
            return y;
        } else {
            return {x.MX, min(x.most_left, y.most_left), x.num + y.num};
        }
    }
    
    segtree(int sz) : n(sz), data(4*n) {}
    
    segtree(const vector<int>& a) : segtree(a.size()) {build(0, 0, n, a);}
    
    void build(int id, int lo, int hi, const vector<int>& a){
        if (lo + 1 == hi){
            data[id] = {a[lo], lo, 1};
            return;
        }
        int mid = (lo+hi)/2;
        build(2*id+1, lo, mid, a);
        build(2*id+2, mid, hi, a);
        data[id] = f(data[id*2+1], data[id*2+2]);
    }
    
    void get(int l, int r){
        T elem = get(0, 0, n, l, r);
        cout << elem.MX << ' ' << elem.most_left + 1 << ' ' << elem.num << '\n';
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
    
    // void set(int p, const T& x){
    //     set(0, 0, n, p, x);
    // }
    
    // void set(int id, int lo, int hi, int p, int x){
    //     if (lo + 1 == hi){
    //         data[id] += x;
    //         return;
    //     }
    //     int mid = (lo + hi) / 2;
    //     if (p < mid){
    //         set(2*id + 1, lo, mid, p, x);
    //     } else {
    //         set(2*id + 2, mid, hi, p, x);
    //     }
    //     data[id] = f(data[2*id + 1], data[2*id + 2]);
    // }
};
    
    
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    segtree<mx> tr(a);
    // cout << "built\n";
    // for (int i = 0; i < tr.data.size(); i++){
    //     cout << tr.data[i] << ' ';
    // } cout << '\n';
    int k;
    cin >> k;
    int x, y;
    for (int i = 0; i < k; i++){
        cin >> x >> y;
        tr.get(--x, y);
    }
}