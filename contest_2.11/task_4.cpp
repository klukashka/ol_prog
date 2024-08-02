#include <bits/stdc++.h>

using namespace std;

mt19937 rng(time(0));

struct node {
    node* left;
    node* right;
    int x, y;
    int val, seg;
    bool to_reverse;
    node(int el): left(nullptr), right(nullptr), x(1), y(rng()), val(el), seg(el), to_reverse(false){}
};

using treap = node*;

const int inf = 1e9 + 1;

int f(int x, int y){
    if (x > y){
        return x;
    } else {
        return y;
    }
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
        return -inf; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    } else {
        return t->seg;  
    }
}

void upd(treap t){
    if (t != nullptr){
        t->x = get_x(t->left) + get_x(t->right) + 1;
        t->seg = f(t->val, f(get_seg(t->left), get_seg(t->right)));
    }
}

void push(treap t){
    if (t == nullptr || !t->to_reverse){
        return ;
    }
    treap lt = nullptr, rt = nullptr;
    lt = t->left;
    rt = t->right;
    t->left = rt;
    t->right = lt;
    if (t->left != nullptr){
        t->left->to_reverse ^= true;
    }
    if (t->right != nullptr){
        t->right->to_reverse ^= true;
    }
    t->to_reverse = false;
}

void print(treap t){
    if (t == nullptr){
        return;
    }
    print(t->left);
    cout << t->val << ' ';
    print(t->right);
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

void reverse(treap t, int l, int r){
    treap t1, t2, t3;
    split(t, r, t2, t3);
    split(t2, l, t1, t2);
    t2->to_reverse ^= true;
    t = merge(merge(t1, t2), t3);
}

int get(treap t, int l, int r){
    treap t1, t2, t3;
    split(t, r, t2, t3);
    split(t2, l, t1, t2);
    // print(t1);
    // cout << " end1\n";
    // print(t2);
    // cout << " end2\n";
    // print(t3);
    // cout << " end3\n";
    int val = t2->seg;
    t = merge(merge(t1, t2), t3);
    return val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    treap t = nullptr;
    int a;
    for (int i = 0; i < n; i++){
        cin >> a;
        treap l = nullptr, r = nullptr, m = nullptr;
        split(t, i, l, r);
        m = new node(a);
        t = merge(merge(l, m), r);
        // print(t);
        // cout << '\n';
    }
    // print(t);
    // cout << '\n';
    int q, v, p;
    for (int i = 0; i < m; i++){
        cin >> q >> v >> p;
        if (q == 1){
            reverse(t, v-1, p);
        } else {
            cout << get(t, v-1, p) << '\n';
        }
    }
    // print(t);
    // cout << '\n';
}