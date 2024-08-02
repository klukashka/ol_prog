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
    string s, ss;
    cin >> s;
    int n = s.size();
    ss = s + s;
    vector<int> nums = z_func(ss);
    for (int i = n - 1; i >= 0; i--){
        if (n % (n - i) == 0 && nums[i] >= n){
            cout << n - i << '\n';
            return 0;
        }
    }
}