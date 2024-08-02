#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// bool check(int i, int j, vector<int>& a){
//     if (a[i-1] != a[j-1] && a[i] == a[j] && a[i+1] == a[j+1]){
//         return true;
//     }
//     if (a[i-1] == a[j-1] && a[i] != a[j] && a[i+1] == a[j+1]){
//         return true;
//     }
//     if (a[i-1] == a[j-1] && a[i] == a[j] && a[i+1] != a[j+1]){
//         return true;
//     }
//     return false;
// }

struct three{
    int first, second, third;
    // three(int first, int second, int third): first(first), second(second), third(third){}
    // bool operator<(const three &ob) const {
    //     return first < ob.first || (first == ob.first && second < ob.second || (second == ob.second && third < ob.third));
    // }
};

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    map<tuple<int, int, int>, int> m;
    for (int i = 1; i < n-1; i++){
        ans += m[{0, a[i], a[i+1]}] - m[{a[i-1], a[i], a[i+1]}];
        m[{0, a[i], a[i+1]}]++;

        ans += m[{a[i-1], 0, a[i+1]}] - m[{a[i-1], a[i], a[i+1]}];
        m[{a[i-1], 0, a[i+1]}]++;

        ans += m[{a[i-1], a[i], 0}] - m[{a[i-1], a[i], a[i+1]}];
        m[{a[i-1], a[i], 0}]++;

        m[{a[i-1], a[i], a[i+1]}]++;
    }
    cout << ans << '\n';
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
