#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
template <class T>
    
struct segtree{
    int n;
    vector<T> data;
    vector<T> delay;
    
    T f(const T& x, const T& y){return x+y;}
    
    segtree(int sz) : n(sz), data(4*n), delay(4*n){}
    
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

    void push(int id, int lo, int hi){
        if (delay[id] == 0){
            return ;
        }
        data[id] = delay[id];
        if (lo + 1 < hi){
            delay[2*id+1] = delay[id];
            delay[2*id+2] = delay[id];
        }
        delay[id] = 0;
    }
    
    T get(int l, int r){
        return get(0, 0, n, l, r);
    }
    T get(int id, int lo, int hi, int l, int r){
        if (r <= lo || hi <= l){
            return T();
        }
        push(id, lo, hi);
        if (l <= lo && hi <= r){
            // cout << data[id] << " from " << id << " id\n";
            // cout << lo << " lo, " << hi << " hi\n";
            return data[id];
        }
        int mid = (lo + hi)/2;
        return f(get(2*id+1, lo, mid, l, r), get(2*id+2, mid, hi, l, r));
    }
    
    void upd(int l, int r, const T& x){
        upd(0, 0, n, l, r, x);
    }

    void upd(int id, int lo, int hi, int l, int r, const ll& x){
        push(id, lo, hi);
        if (r <= lo || hi <= l){
            return ;
        }
        if (l <= lo && hi <= r){
            delay[id] = x;
            push(id, lo, hi);
            return ;
        }
        int mid = (lo + hi) / 2;
        upd(2*id+1, lo, mid, l, r, x);
        upd(2*id+2, mid, hi, l, r, x);
        data[id] = f(data[2*id+1], data[2*id+2]);
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
    int k;
    cin >> k;
    int q;
    while (k--){
        cin >> q;
        if (q == 0){
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            tr.upd(l, r, c);
        } else {
            int pos;
            cin >> pos;
            pos--;
            cout << tr.get(pos, pos + 1) << '\n';
        }
        // for (int i = 0; i < tr.data.size(); i++){
        //     cout << tr.data[i] << ' ';
        // }
        // cout << "\n";
    }
}