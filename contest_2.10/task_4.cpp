#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
int inf = 1e9;
#define all(x) x.begin(), x.end()

void merge(vector<int>& d1, vector<int>& d2, vector<int>& d){
    int c1 = 0, c2 = 0, c = 0;
    while (c1 != d1.size() && c2 != d2.size()){
        if (d1[c1] <= d2[c2]){
            d[c] = d1[c1];
            c1++;
        } else {
            d[c] = d2[c2];
            c2++;
        }
        c++;
    }
    while (c1 != d1.size()){
        d[c] = d1[c1];
        c1++;
        c++;
    }
    while (c2 != d2.size()){
        d[c] = d2[c2];
        c2++;
        c++;
    }
}

int find_val(vector<int> d, int x){
    int ind = lower_bound(all(d), x) - d.begin();
    if (ind < d.size()){
        return d[ind];
    } else {
        return inf;
    }
}

struct segtree{
    int n;
    vector<vector<int>> data;
    
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    segtree tr(a);
    int k;
    cin >> k;
    int l, r, x, ans;
    while (k--){
        cin >> l >> r >> x;
        l--;
        ans = tr.get(l, r, x);
        if (ans == inf){
            cout << "None\n";
        } else {
            cout << ans << '\n';
        }
    }
}