#include <bits/stdc++.h>

using namespace std;

const int R = 12;
int inf = 1e9;

bool check(int x, int n){
    return 0 <= x && x < n;
}

struct tower{
    int x, y, p;
};

bool enough(int x1, int y1, int x2, int y2, int r){
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= r*r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 0){
        cout << "0\n";
        return 0;
    }
    vector<string> field(n);
    for (int i = 0; i < n; i++){
        cin >> field[i];
    }
    vector<tower> towers(k);
    for (int i = 0; i < k; i++){
        cin >> towers[i].x >> towers[i].y >> towers[i].p;
        towers[i].x--; towers[i].y--;
    }
    vector<vector<int>> inside(k, vector<int>(R+1, 0));
    for (int i = 0; i < k; i++){
        for (int r = 1; r <= R; r++){
            for (int x = towers[i].x - r; x <= towers[i].x + r; x++){
                for (int y = towers[i].y - r; y <= towers[i].y + r; y++){
                    if (check(x, n) && check(y, m)){
                        if (field[x][y] == '#' && enough(x, y, towers[i].x, towers[i].y, r)){
                            inside[i][r]++;
                        }
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
            if (ans < dp[i][mask] - excess){
                ans = dp[i][mask] - excess;
                // for (int r = 0; r < R; r++){
                //     if (mask & (1 << r)){
                //         cout << 1;
                //     } else {
                //         cout << 0;
                //     }
                //     cout << '\n';
                // }
            }
            // ans = max(ans, dp[i][mask] - excess);
        }
    }
    cout << ans << '\n';
}