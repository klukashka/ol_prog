#include <bits/stdc++.h>

using namespace std;

vector<int> z_func(const string& s){
    int n = s.size();
    vector<int> z(n);
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
    z[0] = 0;
    return z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    // ifstream file;
    // file.open("task_d.in");
    // file >> s;
    cin >> s;
    int m = s.size();
    int ans = 0;
    for (int i = 1; i <= m; i++){
        string p = s.substr(0, i);
        reverse(p.begin(), p.end());
        vector<int> nums = z_func(p);
        int mx = 0;
        for (int v : nums){
            mx = max(mx, v);
        }
        ans += i - mx;
    }
    cout << ans << '\n';
}