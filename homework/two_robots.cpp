#include <bits/stdc++.h>

using namespace std;

int mx(vector<vector<vector<int>>>& d, int i, int j, int k){
        return max(d[i-1][j-1][k-1], max(
                    d[i-1][j-1][k], max(
                        d[i-1][j-1][k+1], max(
                            d[i-1][j][k-1], max(
                                d[i-1][j][k], max(
                                    d[i-1][j][k + 1], max(
                                        d[i-1][j+1][k-1], max(
                                            d[i-1][j+1][k], d[i-1][j+1][k+1]
                                            )
                                        )
                                    )
                                )
                            )
                        )
                    )
                );
}

vector<vector<vector<int>>> cherryPickup(vector<vector<int>>& grid) {

    int rows = grid.size(), cols = grid[0].size();
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols + 2, vector<int>(cols + 2, 0)));

    dp[0][1][cols] = grid[0][0] + grid[0][cols - 1];
    for (int i = 1; i < rows; i++){
        for (int j = 1; j <= cols; j++){
            for (int k = 1; k <= cols; k++){
                if (k != j){
                    dp[i][j][k] = mx(dp, i, j, k) + grid[i][j] + grid[i][k];
                } else {
                    dp[i][j][k] = mx(dp, i, j, k) + grid[i][k];
                }
            }
        }
    }
    int mx_val = 0;
    for (int i = 1; i <= cols; i++){
        for (int j = 1; j <= cols; j++){
            if (dp[rows - 1][i][j] > mx_val){
                mx_val = dp[rows - 1][i][j];
            }
        }
    }
    return dp;
}

int main(){
    vector<vector<int>> p = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}}; // {{1,0,0,0,0,0,1}, {2,0,0,0,0,3,0}, {2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}}; 
    vector<vector<vector<int>>> a = cherryPickup(p);
    
    for (int i = 0; i < p.size(); i++){
        for (int j = 0; j <= p[0].size() + 1; j++){
            for (int k = 0; k <= p[0].size() + 1; k++){
                cout << a[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << "||||||||\n";
    }

    int mx_val = 0;
    for (int i = 1; i <= p[0].size(); i++){
        for (int j = 1; j <= p[0].size(); j++){
            if (a[p.size() - 1][i][j] > mx_val){
                mx_val = a[a.size() - 1][i][j];
            }
        }
    }
    cout << mx_val << '\n';
}