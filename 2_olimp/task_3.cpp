#include <bits/stdc++.h>

using namespace std;

struct coord{
    int x, y;
};

bool check(int x, int n){
    return 0 <= x && x < n;
}
struct info{
    int total, red, last;
};
int inf = 1e9;
// r - 0, g - 1

vector<coord> to_visit = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void dfs(coord start, coord prev, coord finish, const vector<vector<char>>& g, vector<vector<info>>& dp, int n, int m){
    for (coord c : to_visit){
        coord next = {start.x + c.x, start.y + c.y};
        if (!check(next.x, n) || !check(next.y, m) || (prev.x == next.x && prev.y == next.y)){
            continue;
        }
        if (dp[next.x][next.y].total != inf){
            continue;
        }
        if (g[next.x][next.y] == '#'){
            continue;
        }
        if (g[next.x][next.y] == '.'){
            if (dp[next.x][next.y].total > dp[start.x][start.y].total + 1){
                dp[next.x][next.y] = dp[start.x][start.y];
                dfs(next, start, finish, g, dp, n ,m);
            } else if (dp[next.x][next.y].total == dp[start.x][start.y].total + 1){
                if (dp[next.x][next.y].red < dp[start.x][start.y].red){
                    dp[next.x][next.y] = dp[start.x][start.y];
                }
            }
        } else if (g[next.x][next.y] == 'f'){
            if (dp[next.x][next.y].total > dp[start.x][start.y].total + 1){
                dp[next.x][next.y] = dp[start.x][start.y];
            } else if (dp[next.x][next.y].total == dp[start.x][start.y].total + 1){
                if (dp[next.x][next.y].red < dp[start.x][start.y].red){
                    dp[next.x][next.y] = dp[start.x][start.y];
                }
            }
        } else if (g[next.x][next.y] == 'g'){
            if (dp[start.x][start.y].last == 0){
                if (dp[next.x][next.y].total > dp[start.x][start.y].total + 1){
                    dp[next.x][next.y] = dp[start.x][start.y];
                    dp[next.x][next.y].total++;
                    dfs(next, start, finish, g, dp, n ,m);
                } else if (dp[next.x][next.y].total == dp[start.x][start.y].total + 1){
                    if (dp[next.x][next.y].red < dp[start.x][start.y].red){
                        dp[next.x][next.y] = dp[start.x][start.y];
                        dp[next.x][next.y].total++;
                        dfs(next, start, finish, g, dp, n ,m);
                    }
                }
            } else {
                continue;
            }
        } else{
            if (dp[start.x][start.y].last == 1){
                if (dp[next.x][next.y].total > dp[start.x][start.y].total + 1){
                    dp[next.x][next.y] = dp[start.x][start.y];
                    dp[next.x][next.y].total++;
                    dfs(next, start, finish, g, dp, n ,m);
                } else if (dp[next.x][next.y].total == dp[start.x][start.y].total + 1){
                    if (dp[next.x][next.y].red < dp[start.x][start.y].red){
                        dp[next.x][next.y] = dp[start.x][start.y];
                        dp[next.x][next.y].total++;
                        dp[next.x][next.y].red++;
                        dfs(next, start, finish, g, dp, n ,m);
                    }
                }
            } else {
                continue;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> field(n, vector<char>(m));
    coord start;
    coord fin;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (field[i][j] == 's'){
                start = {i, j};
            }
            if (field[i][j] == 'f'){
                fin = {i, j};
            }
        }
    }
    vector<vector<info>> dp(n, vector<info>(m, {inf, 0, -1}));
    dp[start.x][start.y] = {0, 0, -1};
    dfs(start, start, fin, field, dp, n, m);
    cout << dp[fin.x][fin.y].total << ' ' << dp[fin.x][fin.y].red << '\n';
}