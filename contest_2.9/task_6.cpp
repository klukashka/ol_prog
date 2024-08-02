#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
template <class T>
struct segtree{
    int n;
    vector<int> data;
    T f(const T& a, const T& b) {return a + b;}
    segtree(int sz): n(sz), data(4*n, 0){}
    segtree(vector<T>& a): segtree(a.size()) {}

    // void build(int id, int lo, int hi, vector<T>& a){
    //     if (lo + 1 == hi){
    //         data[id] = a[lo];
    //         return ;
    //     }
    //     int mid = (lo + hi) / 2;
    //     build(2*id+1, lo, mid, a);
    //     build(2*id+2, mid, hi, a);
    //     data[id] = f(data[2*id+1], data[2*id+2]);
    // }

    T get(const int& l, const int& r){
        return get(0, 0, n, l ,r);
    }

    T get(int id, int lo, int hi, const int& l, const int& r){
        if (r <= lo || hi <= l){
            return T();
        }
        if (l <= lo && hi <= r){
            // cout << data[id] << " from " << id << '\n';
            // cout << lo << " lo, " << hi << " hi\n";
            // cout << l << " l, " << r << " r\n";
            return data[id];
        }
        int mid = (lo + hi) / 2;
        // cout << data[2*id + 1] << " from " << 2*id+1 << ", " << data[2*id+2] << " from " << 2*id + 2 << '\n';
        return f(get(2*id+1, lo, mid, l, r), get(2*id+2, mid, hi, l, r));
    }

    void set(int p, const int& x){
        return set(0, 0, n, p, x);
    }

    void set(int id, int lo, int hi, int p, const int& x){
        if (lo + 1 == hi){
            data[id] = x;
            return ;
        }
        int mid = (lo + hi) / 2;
        if (p < mid){
            set(2*id+1, lo, mid, p, x);
        } else {
            set(2*id+2, mid, hi, p, x);
        }
        data[id] = f(data[2*id+1], data[2*id+2]);
    }
};

struct info{
    int first, last, num, ans;
};

bool comparator1(const info& a, const info& b){
    return a.last < b.last;
}

bool comparator2(const info& a, const info& b){
    return a.num < b.num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<info> quests(q);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < q; i++){
        cin >> quests[i].first >> quests[i].last;
        quests[i].first--;
        quests[i].num = i;
    }
    sort(all(quests), comparator1);
    // for (int i = 0; i < n; i++){
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';

    segtree tr(a);
    unordered_map<int, int> latest;
    int c_on_numbers = 0, c_on_quests = 0;
    while (c_on_numbers < n){
        while (quests[c_on_quests].last == c_on_numbers){
            quests[c_on_quests].ans = tr.get(quests[c_on_quests].first, quests[c_on_quests].last);
            // cout << quests[c_on_quests].ans << " ans  |||| " << quests[c_on_quests].first << "|||||" << quests[c_on_quests].last << '\n';
            c_on_quests++;
        }
        int val = a[c_on_numbers];
        if (latest.find(val) == latest.end()){
            tr.set(c_on_numbers, 1);
        } else {
            tr.set(c_on_numbers, 1);
            tr.set(latest[val], 0);
        }
        latest[val] = c_on_numbers;
        c_on_numbers++;
        // for (int i = 0; i < tr.data.size(); i++){ // useless
        //     cout << tr.data[i] << ' ';
        // }
        // cout << " end\n\n";
    }
    while (quests[c_on_quests].last == c_on_numbers){
        quests[c_on_quests].ans = tr.get(quests[c_on_quests].first, quests[c_on_quests].last);
        // cout << quests[c_on_quests].ans << " ans  |||| " << quests[c_on_quests].first << "|||||" << quests[c_on_quests].last << '\n';
        c_on_quests++;
    }
    sort(all(quests), comparator2);
    for (int i = 0; i < q; i++){
        cout << quests[i].ans << '\n';
    }
}