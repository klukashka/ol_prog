#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int sm(vector<int>& a){
    int res = 0; 
    for (int i = 0; i < a.size(); i++){
        res = res + a[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> rows(n);
    vector<pair<int, int>> cols(n);
    for (int i = 0; i < n; i++){
        rows[i] = {sm(a[i]), i};
    }
    for (int i = 0; i < n; i++){
        cols[i] = {0, i};
        for (int j = 0; j < n ;j++){
            cols[i].first += a[j][i];
        }
    }
    int min_row_ind = rows[0].second;
    int max_row_ind = rows[0].second;
    int min_col_ind = cols[0].second;
    int max_col_ind = cols[0].second;
    int norm_sm;
    bool same_rows = true, same_cols = true;
    for (int i = 0 ; i < n; i++){
        if (rows[i].first < rows[min_row_ind].first){
            same_rows = false;
            min_row_ind = i;
        }
        if (cols[i].first < cols[min_col_ind].first){
            same_cols = false;
            min_col_ind = i;
        }
        if (rows[i].first > rows[max_row_ind].first){
            same_rows = false;
            max_row_ind = i;
        }
        if (cols[i].first > cols[max_col_ind].first){
            same_cols = false;
            max_col_ind = i;
        }
    }
    if (rows[min_row_ind].first == rows[max_row_ind].first){
        norm_sm = rows[min_row_ind].first;
    } else {
        for (int i = 0; i < n; i++){
            if (rows[i].first != rows[min_row_ind].first && rows[i].first != rows[max_row_ind].first){
                norm_sm = rows[i].first;
                break;
            }
        }
    }
    // cout << norm_sm << same_rows << same_cols << "asf\n";
    // for (int i = 0; i < n; i++){
    //     cout << rows[i].first << ' ';
    // } cout << '\n';
    // for (int i = 0; i < n; i++){
    //     cout << cols[i].first << ' ';
    // } cout << '\n';

    if (!same_cols && !same_rows){
        cout << max_row_ind + 1 << ' ' << max_col_ind + 1 << '\n';
        cout << min_row_ind + 1 << ' ' << min_col_ind + 1 << '\n';
        return 0;
    } 
    if (same_rows){
        // go through rows
        int delta = abs(norm_sm - cols[min_col_ind].first);
        // cout << delta << '\n';
        for (int i = 0; i < n; i++){
            if (a[i][min_col_ind] + delta == a[i][max_col_ind]){
                cout << i + 1 << ' ' << max_col_ind + 1 << '\n';
                cout << i + 1 << ' ' << min_col_ind + 1 << '\n';
                return 0;
            }
        }
        return 0;
    }
    if (same_cols){
        // go through cols
        int delta = abs(norm_sm - rows[min_row_ind].first);
        // cout << delta << '\n';
        for (int i = 0; i < n; i++){
            if (a[min_row_ind][i] + delta == a[max_row_ind][i]){
                cout << max_row_ind + 1 << ' ' << i + 1 << '\n';
                cout << min_row_ind + 1 << ' ' << i + 1 << '\n';
                return 0;
            }
        }
        return 0;
    }
}