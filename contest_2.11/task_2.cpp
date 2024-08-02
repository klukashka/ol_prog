#include <bits/stdc++.h>

using namespace std;

mt19937 rng(time(0));

struct node {
    node* left;
    node* right;
    int x, y;
    int val;
    node(int el): left(nullptr), right(nullptr), x(1), y(rng()), val(el){}
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

// int get_seg(treap t){
//     if (t == nullptr){
//         return -inf; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     } else {
//         return t->seg;  
//     }
// }

void upd(treap t){
    if (t != nullptr){
        t->x = get_x(t->left) + get_x(t->right) + 1;
        // t->seg = f(t->val, f(get_seg(t->left), get_seg(t->right)));
    }
}

void split(treap t, int x0, treap& l, treap& r){
    if (t == nullptr){
        l = nullptr;
        r = nullptr;
        return;
    }
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
    int n, m;
    cin >> n >> m;
    treap t = nullptr;
    for (int i = 1; i <= n; i++){
        treap l = nullptr, r = nullptr, m = nullptr;
        split(t, i-1, l, r);
        m = new node(i);
        t = merge(merge(l, m), r);
    }
    for (int i = 0; i < m; i++){
        int v, p;
        cin >> v >> p;
        treap l = nullptr, r = nullptr, m = nullptr;
        split(t, p, m, r);
        split(m , v - 1, l, m);
        merge(merge(m, l), r);
    }
    print(t);
    cout << '\n';
}