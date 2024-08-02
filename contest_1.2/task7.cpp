#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
ll MOD = 1e9 + 7;

graph mult(graph a, graph b){
    int sm;
    graph res(a.size(), vector<ll>(b[0].size()));
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b[0].size(); j++){
            sm = 0;
            for (int k = 0; k < b.size(); k++){
                sm = (sm + a[i][k] * b[k][j]) % MOD;
            }
            res[i][j] = sm;
        }
    }
    return res;
}

graph power(graph a, ll p){
    graph res(a.size(), vector<ll>(a.size(), 0));
    for (int i = 0; i < a.size(); i++){
        res[i][i] = 1;
    }
    while (p > 0){
        if (p % 2 == 1){
            res = mult(res, a);
        }
        p = p / 2;
        a = mult(a, a);
    }
    return res;
}

graph transpose(graph& a){
    graph b(a[0].size(), vector<ll>(a.size()));
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[0].size(); j++){
            b[j][i] = a[i][j];
        }
    }
    return b;
}

void print(graph& g){
    for (int i = 0; i < g.size(); i++){
        for (int j = 0; j < g[0].size(); j++){
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    graph g(n, vector<ll>(n, 0));
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = 1;
    }
    graph g_t = transpose(g);
    graph ans = power(g_t, k);
    // print(ans);
    // cout << '\n';
    // ll sm = 0;
    // for (int i = 0; i < ans.size(); i++){
    //     sm = (sm + ans[i][0]) % MOD;
    // }
    cout << ans[0][0] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

}