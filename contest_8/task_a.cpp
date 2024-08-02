#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> numbers(n + 2);
    for (int i = 0; i < q; i++){
        int l, r, v;
        cin >> l >> r >> v;
        numbers[l].push_back(v);
        numbers[r + 1].push_back(-v);
    }
    ll sm = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < numbers[i].size(); j++){
            sm = sm + numbers[i][j];
        }
        cout << sm << ' ';
    }
    cout << '\n';
}