#include <bits/stdc++.h>

using namespace std;


using ll = long long;
ll inf = 1e18;
#define all(x) x.begin(), x.end()

struct info{
    ll sm; 
    int amount;
}; 

struct segtree{
    int n;
    vector<vector<info>> data;
    
    int f(const int& x, const int& y){return min(x, y);}
    
    segtree(int sz) : n(sz), data(4*n){}
    
    segtree(const vector<int>& a) : segtree(a.size()) {build(0, 0, n, a);}
    
    void build(int id, int lo, int hi, const vector<int>& a){
        if (lo + 1 == hi){
            data[id].push_back(a[lo]);
            // for (int i = 0; i < data[id].size(); i++){
            //     cout << data[id][i] << ' ';
            // }
            // cout << "  - " << id << '\n';
            return;
        }
        int mid = (lo+hi)/2;
        build(2*id+1, lo, mid, a);
        build(2*id+2, mid, hi, a);
        data[id].resize(data[2*id+1].size() + data[2*id+2].size());
        merge(data[2*id+1], data[2*id+2], data[id]);
        // for (int i = 0; i < data[id].size(); i++){
        //     cout << data[id][i] << ' ';
        // }
        // cout << "  - " << id << '\n';
    }
    
    int get(int l, int r, int x){
        return get(0, 0, n, l, r, x);
    }
    int get(int id, int lo, int hi, int l, int r, int x){
        if (r <= lo || hi <= l){
            return inf;
        }
        if (l <= lo && hi <= r){
            return find_val(data[id], x);
        }
        int mid = (lo + hi)/2;
        return f(get(2*id+1, lo, mid, l, r, x), get(2*id+2, mid, hi, l, r, x));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, t, x;
    
    cin >> q;
    while (q--){
        cin >> t >> x;
        if (t == 1){
            
        } else if (t == 2){
            
        } else {
            
        }
    }
}