#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using grid = vector<string>;
using pll = pair<ll, int>;
using pii = pair<int, int>;

const int inf = 1e9;
const vector<vector<int>> step = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {0, -1}, {-1, -1}, {-1, 0}, {1, -1}};

// struct item{
//     int to, from, w;
// };

struct coord{
    int x, y;
};

struct dp_info{
    int boots;
    int path;
    coord xy;
};

bool check(int x, int n){
    return 0 <= x && x < n;
}

struct compare{
    bool operator()(const dp_info l, const dp_info r) const { 
        if (l.boots != r.boots){
            return l.boots > r.boots; 
        } else {
            return l.path > r.path;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin >> n >> m;
    coord fridge, comp;
    cin >> comp.x >> comp.y;
    comp.x--;
    comp.y--;
    cin >> fridge.x >> fridge.y;
    fridge.x--;
    fridge.y--;
    grid g(n);
    for (int i = 0; i < n; i++){
        cin >> g[i];
    }
    vector<vector<int>> dp_path(n, vector<int>(m, inf));
    vector<vector<int>> dp_shoes(n, vector<int>(m, inf));
    dp_path[comp.x][comp.y] = 0;
    dp_shoes[comp.x][comp.y] = 0;
    vector<vector<bool>> been_there(n, vector<bool>(m, false));
    priority_queue<dp_info, vector<dp_info>, compare> q;
    q.push({dp_shoes[comp.x][comp.y], dp_path[comp.x][comp.y], {comp.x, comp.y}});
    while (q.size()){
        dp_info cur = q.top();
        coord u = cur.xy;
        q.pop();
        if (been_there[u.x][u.y]){
            continue;
        }
        been_there[u.x][u.y] = true;
        for (int i = 0; i < 8; i++){
            coord v = {u.x + step[i][0], u.y + step[i][1]};
            if (check(v.x, n) && check(v.y, m) && g[v.x][v.y] != '#'){
                if (g[v.x][v.y] == g[u.x][u.y]){
                    if (dp_shoes[u.x][u.y] < dp_shoes[v.x][v.y]){
                        dp_shoes[v.x][v.y] = dp_shoes[u.x][u.y];
                        dp_path[v.x][v.y] = dp_path[u.x][u.y] + 1;
                        q.push({dp_shoes[v.x][v.y], dp_path[v.x][v.y], {v.x, v.y}});
                    } else if (dp_shoes[u.x][u.y] == dp_shoes[v.x][v.y] && (dp_path[u.x][u.y] + 1 < dp_path[v.x][v.y])){
                        dp_path[v.x][v.y]= dp_path[u.x][u.y] + 1;
                        q.push({dp_shoes[v.x][v.y], dp_path[v.x][v.y], {v.x, v.y}});
                    }
                } else {
                    if (dp_shoes[u.x][u.y] + 1 < dp_shoes[v.x][v.y]){
                        dp_shoes[v.x][v.y] = dp_shoes[u.x][u.y] + 1;
                        dp_path[v.x][v.y] = dp_path[u.x][u.y] + 1;
                        q.push({dp_shoes[v.x][v.y], dp_path[v.x][v.y], {v.x, v.y}});
                    } else if (dp_shoes[u.x][u.y] + 1 == dp_shoes[v.x][v.y] && (dp_path[u.x][u.y] + 1 < dp_path[v.x][v.y])){
                        dp_path[v.x][v.y]= dp_path[u.x][u.y] + 1;
                        q.push({dp_shoes[v.x][v.y], dp_path[v.x][v.y], {v.x, v.y}});
                    }
                }
                // cout << '\n';
                // for (int i = 0; i < n; i++){
                //     for (int j = 0; j < m; j++){
                //         if (dp_path[i][j] != inf){
                //             cout << dp_path[i][j] << ' ' << dp_shoes[i][j] << " ; ";
                //         } else {
                //             cout << "inf" << ' ' << "inf" << " ; ";
                //         }
                //     }
                //     cout << '\n';
                // }
            }
        }
    }
    if (dp_shoes[fridge.x][fridge.y] != inf){
        cout << dp_path[fridge.x][fridge.y] + 1 << ' ' << dp_shoes[fridge.x][fridge.y] << '\n';
    } else {
        cout << "0 0\n";
    }
}