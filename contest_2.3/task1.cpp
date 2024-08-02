#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
using pii = pair<int, int>;
    
struct dsu{
    int n;
    vector<int> leader;
    vector<ll> mn;
    vector<ll> mx;
    vector<ll> rank;
    vector<ll> sm;
    dsu(int _n) : n(_n), leader(n), mn(n), mx(n), sm(n), rank(n, 1){
        for (int i = 0; i < n; i++){
            mx[i] = i;
            mn[i] = i;
            sm[i] = i + 1;
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
        sm[lu] += sm[lv];
        mn[lu] = min(mn[lu], mn[lv]);
        mx[lu] = max(mx[lu], mx[lv]);
        mn[u] = mn[lu];
        mx[u] = mx[lu];
        sm[u] = sm[lu];
        mn[v] = mn[lu];
        mx[v] = mx[lu];
        sm[v] = sm[lu];
        mn[lv] = mn[lu];
        mx[lv] = mx[lu];
        sm[lv] = sm[lu];

        leader[lv] = lu;
        return true;
    }
};
    
using edge = tuple<int, int>;
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge> e(m);
    dsu d(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        e[i] = {u, v};
    }
    for (edge el : e){
        d.join(get<0>(el), get<1>(el));
        cout << d.sm[d.leader[get<0>(el)]] << ' ' << d.mn[d.leader[get<0>(el)]] + 1 << ' ' << d.mx[d.leader[get<0>(el)]] + 1 << '\n';
        // for (int i = 0; i < n; i++){
        //     cout << d.sm[i] << ' ';
        // } cout << '\n';
        // for (int i = 0; i < n; i++){
        //     cout << d.leader[i] + 1 << ' ';
        // } cout << '\n';
        // for (int i = 0; i < n; i++){
        //     cout << d.mn[i] + 1 << ' ';
        // } cout << '\n';
        // for (int i = 0; i < n; i++){
        //     cout << d.mx[i]+ 1 << ' ';
        // } cout << "\n\n";
    }
}