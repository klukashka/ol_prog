#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
#define all(x) x.begin(), x.end()

void solve(){
    int n;
    cin >> n;
    unordered_map<int, int> a(n);
    int val;
    for (int i = 0 ; i < n; i++){
        cin >> val;
        a[val]++;
    }
    if (n < 3){
        cout << 0 << '\n';
        return;
    }
    int res = 0;
    for (auto const& [key, val] : a){
        res += val / 3;
    }
    cout << res << '\n';
    return;
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