#include <bits/stdc++.h>

using namespace std;

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
        u--;
        v--;
        //d.join(u, v);
        e[i] = {u, v};
        //cout << d.rank[d.find(u)] << '\n';
    }
    int comp = n;
    vector<int> ans;
    for (int i = e.size()-1; i > -1; i--){
        ans.push_back(comp);
        if (d.join(get<0>(e[i]), get<1>(e[i]))){
            comp--;
        }
    }
    for (int i = ans.size() - 1; i > -1; i--){
        cout << ans[i] << '\n';
    }
}