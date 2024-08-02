#include <bits/stdc++.h>

using namespace std;

vector<int> z_func(const string& s){
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        z[i] = max(0, min(z[i-l], r-i));
        while (i + z[i] < n && s[z[i] + i] == s[z[i]]){
            z[i]++;
        }
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, p, sp;
    cin >> s >> p;
    sp = p + '$' + s;
    vector<int> nums = z_func(sp);
    // for (int v : nums){
    //     cout << v << ' ';
    // }
    // cout << '\n';
    int ans = 0, n = p.size();
    for (int i = n + 1; i < sp.size(); i++){
        if (nums[i] == n){
            ans++;
        }
    }
    if (ans > 0){
        cout << "TAK" << '\n' << ans << '\n';
    } else {
        cout << "NIE" << '\n';
    }
}