#include <bits/stdc++.h>
    
using namespace std;
using grid = vector<string>;
    
bool check(int x, int n){
    return 0 <= x && x < n;
}
    
void bfs(vector<vector<char>>& new_grid, int i, int j, char symb){
    // for (int i = 0; i < new_grid.size(); i++){
    //     for (int j = 0; j < new_grid[0].size(); j++){
    //         cout << new_grid[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    if (check(i, new_grid.size()) && check(j, new_grid[0].size())){
        if (new_grid[i][j] != '#' && new_grid[i][j] == '.'){
            new_grid[i][j] = symb;
            bfs(new_grid, i, j+1, symb);
            bfs(new_grid, i-1, j, symb);
            bfs(new_grid, i+1, j, symb);
            bfs(new_grid, i, j-1, symb);
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
    vector<vector<char>> new_grid(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] != '.'){
                new_grid[i][j] = g[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] != '.' && g[i][j] != '#'){
                bfs(new_grid, i+1, j, new_grid[i][j]);
                bfs(new_grid, i, j+1, new_grid[i][j]);
                bfs(new_grid, i-1, j, new_grid[i][j]);
                bfs(new_grid, i, j-1, new_grid[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (char v : new_grid[i]){
            cout << v;
        }
        cout << '\n';
    }
    
}