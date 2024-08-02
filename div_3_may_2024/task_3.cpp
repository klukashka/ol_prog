#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

int mod = 1e9 + 7;
// bool prime(int x){
//     for (int i = 2; i * i < x; i++){
//         if (x % i == 0){
//             return false;
//         }
//     }
//     return true;
// }

void solve(){
    int n;
    cin >> n;
    vector<int> x(n-1);
    for (int i = 0; i < n-1; i++){
        cin >> x[i];
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
    for (int v : ans){
        cout << v << ' ';
    }
    cout << '\n';
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