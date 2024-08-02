#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()

struct dsu{
    int n;
    vector<int> leader;
    vector<int> rank;
    dsu(int _n) : n(_n), leader(n), rank(n, 1){
        for (int i = 0; i < n; i++){
            leader[i] = i;
        }}
    int find(int u){
        if (leader[u] == u){
            return u;
        }
        leader[u] = find(leader[u]);
        return leader[u];
    }
    bool join(int u, int v){
        int lu = find(u);
        int lv = find(v);
        if (lv == lu){
            return false;
        }
        if (rank[lu] < rank[lv]){
            swap(lu, lv);
        }
        rank[lu] += rank[lv];
        leader[lv] = lu;
        return true;
    }
};

struct edge{
    ll w;
    int from, to;
};

bool compare(const edge& a, const edge& b){
    return a.w < b.w;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dsu d(n + 1);
    ll total = 0;
    vector<edge> arr;
    for (int i = 0; i < n; i++){
        ll a;
        cin >> a;
        arr.push_back({a, i, n});
    }
    for (int i = 0; i < m; i++){
        // for (int i = 0; i < n; i++){
        //     cout << d.sm[i] << ' ';
        // }cout << '\n';
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--; v--;
        arr.push_back({c, u, v});
    }
    sort(all(arr), compare);
    for (int i = 0; i < arr.size(); i++){
        if (d.join(arr[i].from, arr[i].to)){
            total += arr[i].w;
        }
    }
    cout << total << '\n';
}