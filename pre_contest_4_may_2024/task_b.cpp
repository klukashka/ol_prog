#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
using pii = pair<int, int>;
    
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
    
using edge = tuple<int, int>;
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
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
    }
    int counter = 0;
    for (int i = 0; i < n; i++){
        if (d.join(i, get<0>(e[0]))){
            counter++;
        }
    }
    if (counter > k){
        cout << "Klingons\n";
    } else {
        cout << "Harmony\n";
    }
}