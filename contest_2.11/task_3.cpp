#include <bits/stdc++.h>

using namespace std;
using ll = long long;

mt19937 rng(time(0));

struct node {
    node* left;
    node* right;
    int x, y;
    int val, seg, delay;
    node(int el): left(nullptr), right(nullptr), x(1), y(rng()), val(el), seg(el), delay(0){}
};

using treap = node*;

// const int inf = 1e9 + 1;

int f(int x, int y){
    // int g = x^y;
    // cout << x << "  x   ^   y  " << y << " = " <<  g << '\n'; 
    return x^y;
}

int get_x(treap t){
    if (t == nullptr){
        return 0;
    } else {
        return t->x;
    }
}

int get_seg(treap t){
    if (t == nullptr){
        return 0;
    } else {
        return t->seg;  
    }
}

void push(treap t){
    if (t == nullptr || t->delay == 0){
        return;
    }
    t->val = f(t->val, t->delay);
    if (t->left != nullptr){
        t->left->delay ^= t->delay;
    }
    if (t->right != nullptr){
        t->right->delay ^= t->delay;
    }
    t->delay = 0;
}

void upd(treap t){
    if (t != nullptr){
        t->x = get_x(t->left) + get_x(t->right) + 1;
        t->seg = f(t->val, f(get_seg(t->left), get_seg(t->right)));
    }
}

void split(treap t, int x0, treap& l, treap& r){
    if (t == nullptr){
        l = nullptr;
        r = nullptr;
        return;
    }
    push(t);
    if (x0 >= 1 + get_x(t->left)){
        split(t->right, x0 - (1 + get_x(t->left)), t->right, r);
        l = t;
    } else {
        split(t->left, x0, l, t->left);
        r = t;
    }
    upd(t);
}

treap merge(treap l, treap r){
    push(l);
    push(r);
    if (l == nullptr){
        return r;
    }
    if (r == nullptr){
        return l;
    }
    if (l->y > r->y){
        l->right = merge(l->right, r);
        upd(l);
        return l;
    } else {
        r->left = merge(l, r->left);
        upd(r);
        return r;
    }
}

void add(treap t, int l, int r, int x){
    treap t1 = nullptr, t2 = nullptr, t3 = nullptr;
    split(t, r, t2, t3);
    split(t2, l, t1, t2);
    t2->delay ^= x;
    t = merge(merge(t1, t2), t3);
}

void print(treap t){
    if (t == nullptr){
        return;
    }
    print(t->left);
    cout << t->val << ' ';
    print(t->right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    treap t = nullptr;
    int a;
    for (int i = 0; i < n; i++){
        cin >> a;
        treap l = nullptr, r = nullptr, m = nullptr;
        split(t, i, l, r);
        m = new node(a);
        t = merge(merge(l, m), r);
    }
    int type, lt, rt, v;
    for (int i = 0; i < q; i++){
        cin >> type >> lt >> rt >> v;
        lt--; rt--;
        if (type == 1){
            add(t, lt, rt + 1, v);
        } else {
            if (rt == lt){
                // cout << "same\n";
                continue;
            }
            v = v % (rt - lt + 1);
            if (v == 0){
                // cout << "same\n";
                continue;
            }
            treap l = nullptr, r = nullptr, m = nullptr;
            split(t, rt + 1, m, r);
            split(m, lt, l, m);
            treap m1 = nullptr, m2 = nullptr;
            rt -= lt;
            split(m, rt+1-v, m1, m2);
            t = merge(l, merge(merge(m2, m1), r));
            // print(t);
            // cout << " wow\n";
        }
    }
    push(t);
    upd(t);
    cout << t->seg << '\n';
}