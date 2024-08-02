#include <bits/stdc++.h>

using namespace std;
using grid = vector<string>;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool check(int x, int n){
    return 0 <= x && x < n;
}

void bfs(int x, int y, const grid& g, vector<vector<int>>& d){
    int n = g.size();
    int m = g[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    d[x][y] = 0;
    while (!q.empty()){
        pair<int, int> el = q.front();
        q.pop();
        x = el.first;
        y = el.second;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!check(nx, n) || !check(ny, m) || g[nx][ny] == '#' || d[nx][ny] != -1){
                continue;
            }
            d[nx][ny] = d[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    grid g(n);
    for (int i = 0; i < n; i++){
        cin >> g[i];
    }
    vector<vector<int>> d(n, vector<int>(m, -1));
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    bfs(x, y, g, d);
    for (int i = 0; i < n; i++){
        for (int v : d[i]){
            cout << v << ' ';
        }
        cout << '\n';
    }
    
}