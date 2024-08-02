#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
template <class T>
    
struct segtree{
    struct node{
        node* left;
        node* right;
        T val;
        node(const T& x): left(nullptr), right(nullptr), val(x) {}
    };
    int n;
    using nodeptr = node*;
    nodeptr root;
    
    T f(const T& x, const T& y){return x + y;}
    
    segtree(int sz) : n(sz), root(nullptr) {}
    
    T get_val(nodeptr u){
        if (u == nullptr){
            return 0;
        } else {
            return u->val;
        }
    }
    void add(int p, const T& x){
        root = add(root, 0, n, p ,x);
    }
    nodeptr add(nodeptr u, int lo, int hi, int p, const T& x){
        if (u == nullptr){
            u = new node(0);
        }
        if (lo + 1 == hi){
            u->val += x;
            return u;
        }
        int mid = (lo + hi) / 2;
        if (p < mid){
            u->left = add(u->left, lo, mid, p, x);
        } else {
            u->right = add(u->right, mid, hi, p, x);
        }
        u->val = f(get_val(u->left), get_val(u->right));
        return u;
    }
    T get(int l, int r){
        return get(root, 0, n, l, r);
    }
    T get(nodeptr u, int lo, int hi, int l, int r){
        if (u == nullptr || r <= lo || hi <= l){
            return 0;
        }
        if (l <= lo && hi <= r){
            return u->val;
        }
        int mid = (lo + hi) / 2;
        return f(get(u->left, lo, mid, l, r), get(u->right, mid, hi, l, r));
    }

};
    
    
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    segtree<ll> st(1e9);
    int k;
    cin >> k;
    int q, x, y;
    for (int i = 0; i < k; i++){
        cin >> q >> x >> y;
        x--;
        if (q == 0){
            cout << st.get(x, y) << '\n';
        } else {
            st.add(x, y);
        }
    }
}