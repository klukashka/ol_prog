#include <bits/stdc++.h>

using namespace std;

struct node {
    node* left;
    node* right;
    int x, y;

    node(int _x, int _y): left(nullptr), right(nullptr), x(_x), y(_y){}
};

using treap = node*;

void split(treap t, int x0, treap& l, treap& r){
    if (t == nullptr){
        l = nullptr;
        r = nullptr;
        return;
    }
    if (x0 < t->x){
        split(t->left, x0, l, t->left);
        r = t;
    } else {
        split(t->right, x0, t->right, r);
        l = t;
    }
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
        return l;
    } else {
        r->left = merge(l, r->left);
        return r;
    }
}

void print(treap t){
    if (t == nullptr){
        cout << "null\n";
        return;
    }
    cout << t->x << ' ' << t->y << '\n';
    print(t->left);
    print(t->right);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    treap t = nullptr;
    for (int i = 0; i < n; i++){
        int k, p;
        cin >> k >> p;
        treap l = nullptr, r = nullptr;
        split(t, k, l, r);
        treap m = new node(k, p);
        t = merge(merge(l, m), r);
    }
    print(t);
}