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

bool check_sq(int a){
    for (int i = 1; i < a; i++){
        if (i * i == a){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    dsu d(n + 1);
    for (int u = 1; u <= n; u++){
        for (int v = 1; v < u; v++){
            if ((v * v + u * u) % k == 0){
                int res = (v * v + u * u) / k;
                if (check_sq(res)){
                    if (!d.join(v, u)){
                        cout << u << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}