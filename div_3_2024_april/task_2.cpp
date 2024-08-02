#include <bits/stdc++.h>

using namespace std;

void build_sq(int a11, int n, int c, int d, vector<vector<int>>& m, map<int, int>& total_sq){
    m[0][0] = a11;
    total_sq[a11] = 0;
    for (int i = 1; i < n; i++){
        m[0][i] = m[0][i-1] + d;
        if (total_sq.find(m[0][i]) == total_sq.end()){
            total_sq[m[0][i]] = 0;
        } else {
            total_sq[m[0][i]]++;
        }
    }
    for (int i = 1; i < n; i++){
        m[i][0] = m[i-1][0] + c;
        if (total_sq.find(m[i][0]) == total_sq.end()){
            total_sq[m[i][0]] = 0;
        } else {
            total_sq[m[i][0]]++;
        }
        for (int j = 1; j < n; j++){
            m[i][j] = m[i][j-1] + d;
            if (total_sq.find(m[i][j]) == total_sq.end()){
                total_sq[m[i][j]] = 0;
            } else {
                total_sq[m[i][j]]++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, c, d;
        cin >> n >> c >> d;
        vector<vector<int>> v(n, vector<int>(n));
        map<int, int> v_st;
        int mn = 1e9;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> v[i][j];
                if (v_st.find(v[i][j]) == v_st.end()){
                    v_st[v[i][j]] = 0;
                } else {
                    v_st[v[i][j]]++;
                }
                mn = min(mn, v[i][j]);
            }
        }
        // cout << mn <<  "   mn\n";
        vector<vector<int>> m(n, vector<int>(n));
        map<int, int> canon_st;
        build_sq(mn, n, c, d, m, canon_st);
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++){
        //         cout << m[i][j] << ' ';
        //     }cout << '\n';
        // } cout << " ----m\n\n";
        bool flag = true;

        for (auto const& [key, val] : v_st){
            if (canon_st.find(key) != canon_st.end()){
                if (canon_st[key] != val){
                    flag = false;
                    break;
                }
            } else {
                flag = false;
                break;
            }
        }
        if (flag){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}