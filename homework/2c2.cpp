#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

// struct compare{
//     bool operator()(const edge& a, const edge& b)const{return get<0>(a) > get<0>(b);}
// };

// bool compare(edge a, edge b){
//     return get<0>(a) > get<0>(b);
// }

using edge = tuple<ll, int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge> e;
    for (int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;v--;
        e.push_back({w, u, v});
    }
    sort(e.begin(), e.end());
    dsu d(n);
    ll ans = 0;
    for (edge el : e){
        if (d.join(get<1>(el), get<2>(el))){
            ans = ans + get<0>(el);
        }
        // cout << "ans " << ans << '\n';
        // for (int i = 0; i < n; i++){
        //     cout << d.leader[i] << ' ';
        // }
        // cout << '\n';
        // for (int i = 0; i < n; i++){
        //     cout << d.rank[i] << ' ';
        // }
        // cout << "\n\n";
    }
    cout << ans << '\n';
}