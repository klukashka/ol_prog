#include <bits/stdc++.h>

using namespace std;

struct tower{
    int x, y, p;
};

int R = 12;
int inf = 2e9;

bool check(int x, int n){
    return 0 <= x && x < n;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);  
    vector<tower> towers(k); 
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
    for (int i = 0; i < k; i++){
        cin >> towers[i].x >> towers[i].y >> towers[i].p;
        towers[i].x--;
        towers[i].y--;
    }
    vector<vector<int>> inside(k, vector<int>(R+1));
    for (int i = 0; i < k; i++){
        int x = towers[i].x;
        int y = towers[i].y;
        for (int r = 1; r <= R; r++){
            for (int dx = -r; dx <= r; dx++){
                for (int dy = -r; dy <= r; dy++){
                    int nx = x + dx;
                    int ny = y + dy;
                    if (!check(nx, n) || !check(ny, m)){
                        continue;
                    }
                    if ((x - nx)*(x - nx) + (y - ny)*(y - ny) <= r * r){
                        inside[i][r] += (grid[nx][ny] == '#');
                    }
                }
            }
        }
    }
    vector<vector<int>> dp(k + 1, vector<int>(1 << R, -inf));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++){
        for (int mask = 0; mask < (1 << R); mask++){
            dp[i][mask] = dp[i-1][mask];
            for (int r = 1; r <= R; r++){
                int j = r - 1;
                if (!(mask & (1 << j))){
                    continue;
                }
                dp[i][mask] = max(dp[i][mask], dp[i-1][mask ^ (1 << j)] + towers[i-1].p * inside[i-1][r]);
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << R); mask++){
        int excess = 0;
        int mult = 3;
        for (int r = 0; r < R; r++){
            if (mask & (1 << r)){
                excess += mult;
            }
            mult *= 3;
        }
        for (int i = 0; i <= k; i++){
            ans = max(ans, dp[i][mask] - excess);
        }
    }
    cout << ans << '\n';
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