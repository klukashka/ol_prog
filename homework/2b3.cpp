#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;

struct edge{
    int from, to;
    ll w;
};

using graph = vector<vector<edge>>;
using item = pair<ll, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    vector<vector<ll>> g(n, vector<ll>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            cout << g[k][i] << ' ';
        }
        cout << '\n';
    }
}