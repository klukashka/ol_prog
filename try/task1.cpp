#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // if (n == 1){
    //     cout << a[0] << '\n';
    //     return ;
    // }
    int max_val = -100;
    for (int i = 0; i < n; i = i + 2){
        if (a[i] > max_val){
            max_val = a[i];
        }
    }
    cout << max_val << '\n';
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