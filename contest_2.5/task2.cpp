#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

struct coord{
    int x, y;
};

const int black = 0;
const int green = 1;
const int red = 2;

struct info{
    int dot;
    int col;
};

bool bfs(int start, graph& g, vector<int>& colour){
    bool bad_gr = false;
    queue<info> q;
    q.push({start, green});
    while (!q.empty()){
        info u = q.front();
        q.pop();
        if (colour[u.dot] != black && colour[u.dot] != u.col){
            bad_gr = true;
            break;
        }
        if (colour[u.dot] == u.col){
            continue;
        }
        colour[u.dot] = u.col;
        int colour_to_print;
        if (u.col == red){
            colour_to_print = green;
        } else {
            colour_to_print = red;
        }
        for (int v : g[u.dot]){
            q.push({v, colour_to_print});
        }
    }
    return bad_gr;
}

bool kunh(int u, vector<int>& mt, vector<bool>& visited, const graph& g, const vector<int>& colour){
    if (visited[u]){
        return false;
    }
    visited[u] = true;
    for (int i : g[u]){
        if (colour[i] != colour[u]){
            if (mt[i] == -1){
                mt[i] = u;
                return true;
            }
            if (kunh(mt[i], mt, visited, g, colour)){
                mt[i] = u;
                return true;
            }
        }
    }
    return false;
}

bool check(int a, int n){
    return 0 <= a && a < n;
}
const vector<coord> df = {{0, 1}, {1, 0}};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph blocks(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int u;
            cin >> u;
            blocks[i][j] = u;
        }
    }
    graph g(n*m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (coord v : df){
                if (check(i + v.x, n) && check(j + v.y, m)){
                    if (blocks[i][j] != blocks[i + v.x][j + v.y]){
                        g[i*m + j].push_back((i+v.x) * m + j + v.y);
                        g[(i+v.x) * m + j + v.y].push_back(i*m + j);
                    }
                }
            }
        }
    }

    vector<int> colour(n*m, black);
    for (int i = 0; i < n*m; i++){
        if (colour[i] == black){
            bfs(i, g, colour);
        }
    }

    vector<bool> visited(n*m, false);
    vector<int> mt(n*m, -1);
    for (int i = 0; i < n*m; i++){
        if (colour[i] == red){
            visited.assign(n, false);
            kunh(i, mt, visited, g, colour);
        }
    }
    // for (int i = 0; i < n*m; i++){
    //     cout << i << " : ";
    //     for (int v : g[i]){
    //         cout << v << ' ';
    //     }
    //     cout << '\n';
    // }
    // for (int i = 0; i < n*m; i++){
    //     cout << i / m << ' ' << i % m << " : " << i << " here";
    //     cout << '\n';
    // }
    vector<vector<int>> bricks(n, vector<int>(m, -1));
    int c = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mt[i*m + j] != -1 && bricks[i][j] == -1){
                bricks[i][j] = c;
                bricks[mt[i*m + j] / m][mt[i*m + j] % m] = c;
                c++;
            }
        }
    }
    // for (int i = 0; i < n; i++){
    //         for (int j = 0; j < m; j++){
    //             cout << bricks[i][j] << ' ';
    //         }
    //         cout << '\n';
    //     } 
    // cout << c << '\n';
    if (c == n*m/2 + 1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << bricks[i][j] << ' ';
            }
            cout << '\n';
        }        
    } else {
        cout << "-1\n";
    }
}