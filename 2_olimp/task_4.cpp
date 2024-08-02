#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void dfs(int u, int prev, const graph& g, vector<vector<int>>& vals, vector<vector<int>>& dp, vector<int>& tin, vector<int>& tout, int& t){
    tin[u] = ++t;
    dp[u] = vals[u];
    for (int v : g[u]){
        if (v == prev){
            continue;
        }
        dfs(v, u, g, vals, dp, tin, tout, t);
        for (int i = 0; i < dp[0].size(); i++){
            dp[u][i] += dp[v][i];
        }
    }
    tout[u] = ++t;
}

// void print_vector(vector<int> v){
//     for (int i = 0; i < v.size();i++){
//         cout << v[i] << ' ';
//     }
//     cout << '\n';
// }

struct edge{
    int from, to;
};

const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void make(int a, vector<int>& powers){
    for (int i : primes){
        while (a % i){
            a = a / i;
            powers[i]++;
        }
    }
}

bool if_div(vector<int> a, vector<int> b){
    for (int i = 0; i < a.size(); i++){
        b[i] -= a[i];
    }
    for (int i = 0; i < a.size(); i++){
        if (b[i] < a[i]){
            return false;
        }
    }
    return true;;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1){
        cout << "0\n";
        return 0;
    }
    graph g(n);
    vector<int> vals(n);
    for (int i = 0; i < n; i++){
        cin >> vals[i];
    }
    vector<vector<int>> powers(n, vector<int>(primes.size() + 1, 0));
    for (int i = 0; i < vals.size(); i++){
        make(vals[i], powers[i]);
    }
    vector<edge> edges(n-1);
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u, v};
    }
    vector<vector<int>> dp(n, vector<int>(primes.size(), 0));
    vector<int> tin(n, 0);
    vector<int> tout(n, 0);
    int t = 0;
    dfs(0, 0, g, powers, dp, tin, tout, t);
    vector<int> ans;
    for (int i = 0; i < n-1; i++){
        if (tin[edges[i].to] > tin[edges[i].from] && tout[edges[i].to] < tout[edges[i].from]){
            if (if_div(dp[edges[i].to], dp[0])){
                ans.push_back(i);
            } else if (if_div(dp[0], dp[edges[i].to])){
                ans.push_back(i);
            }
        } else {
            if (if_div(dp[edges[i].from], dp[0])){
                ans.push_back(i);
            } else if (if_div(dp[0], dp[edges[i].from])){
                ans.push_back(i);
            }
        }
    }
    // print_vector(dp);
    // cout << '\n';
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}