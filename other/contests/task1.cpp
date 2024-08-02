#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, y;
    cin >> x >> y;
    int ans = 0;
    ans += y / 2;
    int one_add = y % 2;
    if (x <= ans * 7){
        cout << ans + one_add<< '\n';
        return;
    }
    x -= ans * 7;
    if (x <= one_add*11){
        cout << ans + one_add << '\n';
        return;
    }
    x -= one_add*11;
    cout << ans + one_add + (x + 14)/15 << '\n';
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
