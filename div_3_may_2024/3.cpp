#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

mt19937 rng(time(0));

void print(vector<int>& x, vector<int> &ans){
    for (int v : x){
        cout << v << ' ';
    }
    cout << '\n';
    for (int v : ans){
        cout << v << ' ';
    }
    cout << '\n';
}

void solve(){
    int n;
    n = rng() % 10;
    cout << n << '\n';
    vector<int> x(n-1);
    for (int i = 0; i < n-1; i++){
        x[i] = rng() % 30;
    }
    vector<int> ans(n);
    ans[0] = x[0] + 1;
    for (int i = 0; i < n-1; i++){
        if (x[i+1] >= x[i]){
            ans[i+1] = x[i+1] * ans[i] + x[i];
        } else {
            ans[i+1] = x[i];
        }
    }
    for (int i = 1; i < n; i++){
        if (ans[i] % ans[i-1] != x[i-1]){
            print(x, ans);
            return;
        }
    }
    // cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}