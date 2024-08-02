#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const double eps = 0.0000001;
const long double inf = 1e18;
struct item{
    int x, y;
};
using pdi = pair<double, int>;
struct edge{
    int from, to;
    double dist;
};
double sq(double x, double a){
    double ans = 0.5 * (x + a/x);
    if (abs(ans - x) < eps){
        return ans;
    }
    return sq(ans, a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<item> coords(n);
    for (int i = 0; i < n; i++){
        cin >> coords[i].x >> coords[i].y;
    }
    vector<vector<edge>> g(n); // where y
    for (int i = 1; i < n-1; i++){
        g[i].push_back({i, i+1, sq(1, (coords[i].x - coords[i+1].x) * (coords[i].x - coords[i+1].x) + 
                                    (coords[i].y - coords[i+1].y) * (coords[i].y - coords[i+1].y))});
        g[i].push_back({i, i-1, sq(1, (coords[i].x - coords[i-1].x) * (coords[i].x - coords[i-1].x) + 
                                    (coords[i].y - coords[i-1].y) * (coords[i].y - coords[i-1].y))});
    }
    g[n-1].push_back({n-1, n-2, sq(1, (coords[n-1].x - coords[n-2].x) * (coords[n-1].x - coords[n-2].x) + 
                                    (coords[n-1].y - coords[n-2].y) * (coords[n-1].y - coords[n-2].y))});
    g[n-1].push_back({n-1, 0, sq(1, (coords[n-1].x - coords[0].x) * (coords[n-1].x - coords[0].x) + 
                                    (coords[n-1].y - coords[0].y) * (coords[n-1].y - coords[0].y))});
    g[0].push_back({0, n-1, sq(1, (coords[0].x - coords[n-1].x) * (coords[0].x - coords[n-1].x) + 
                                    (coords[0].y - coords[n-1].y) * (coords[0].y - coords[n-1].y))});
    g[0].push_back({0, 1, sq(1, (coords[0].x - coords[1].x) * (coords[0].x - coords[1].x) + 
                                    (coords[0].y - coords[1].y) * (coords[0].y - coords[1].y))});
    long double res_sum = inf;
    // for (int i = 0; i < n; i++){
    //     for (edge v : g[i]){
    //         cout << v.from + 1 << ' ' << v.to + 1 << ' ' << v.dist << '\n';
    //     }
    // }
    for (int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            if ((abs(a - b) % n) <= 1 || (abs(a - b) % n) >= (n - 1)){
                continue;
            }
            long double sum = 0;
            g[a].push_back({a, b, sq(1, (coords[a].x - coords[b].x) * (coords[a].x - coords[b].x) + 
                                    (coords[a].y - coords[b].y) * (coords[a].y - coords[b].y))});
            g[b].push_back({b, a, sq(1, (coords[b].x - coords[a].x) * (coords[b].x - coords[a].x) + 
                                    (coords[b].y - coords[a].y) * (coords[b].y - coords[a].y))});
            for (int s = 0; s < n; s++){
                vector<double> dp(n, inf);
                vector<bool> been_there(n, false);
                dp[s] = 0;
                priority_queue<pdi, vector<pdi>, greater<pdi>> q;
                q.push({dp[s], s});
                while (q.size()){
                    pdi cur = q.top();
                    q.pop();
                    int u = cur.second;
                    if (been_there[u]){
                        continue;
                    }
                    for (edge v : g[u]){
                        if (dp[u] + v.dist < dp[v.to]){
                            dp[v.to] = dp[u] + v.dist;
                            q.push({dp[v.to], v.to});
                        }
                    }
                }
                for (int k = 0; k < n; k++){
                    sum += dp[k];
                }
            }
            if (sum < res_sum){
                res_sum = sum;
            }
            g[a].pop_back();
            g[b].pop_back();
        }
    }
    cout << fixed << setprecision(7) << res_sum << '\n';
}