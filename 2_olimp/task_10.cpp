#include <bits/stdc++.h>

using namespace std;

vector<int> z_func(vector<char>& s){
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        z[i] = max(0, min(z[i-l], r-i));
        while (i + z[i] < n && s[z[i] + i] == s[z[i]]){
            z[i]++;
        }
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

template <class T> 
struct segtree{
    int n;
    vector<T> data;
    vector<T> delay;
    
    T f(const T& x, const T& y){
        vector<char> res(x.size() + y.size());
        for (int i = 0; i < x.size(); i++){
            res[i] = x[i];
        }
        for (int i = 0; i < y.size(); i++){
            res[i + x.size()] = y[i];
        }
        return z_func(res);
    }
    
    segtree(int sz) : n(sz), data(4*n), delay(4*n) {}
    
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
            delay[2*id+1] += delay[id];
            delay[2*id+2] += delay[id];
        }
        delay[id] = ;
    }
    
    T get(int l, int r){
        return get(0, 0, n, l, r);
    }
    T get(int id, int lo, int hi, int l, int r){
        if (r <= lo || hi <= l){
            return T(-1e18);
        }
        if (l <= lo && hi <= r){
            return data[id];
        }
        int mid = (lo + hi)/2;
        return f(get(2*id+1, lo, mid, l, r), get(2*id+2, mid, hi, l, r));
    }
    
    void upd(int l, int r, const T& x){
        upd(0, 0, n, l, r, x);
    }

    void upd(int id, int lo, int hi, int l, int r, const T& x){
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
    int n, q;
    cin >> n >> q;
    vector<char> s;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    while (q--){
        int t;
        cin >> t;
        if (t == 1){

        } else {

        }
    }
}