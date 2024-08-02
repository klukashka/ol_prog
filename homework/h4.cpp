#include <bits/stdc++.h>
#include <tuple>
using namespace std;
using ll = long long int;

struct pair_{
    int first, second;
};

bool compare(pair_ a, pair_ b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair_> v(n);
    vector<pair_> p;
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);

    int ans = 0;
    int prev = -1e9 + 1;
    for (int i = 0; i < n; i++){
        if (v[i].first >= prev){
            ans++;
            prev = v[i].second;
        }
    }
    cout << ans << '\n';
}