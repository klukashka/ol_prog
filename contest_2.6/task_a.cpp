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
    string s, p, sp, ps;
    cin >> s >> p;
    sp = p + '$' + s;
    ps = s + '$' + p;
    int n = p.size();
    vector<int> nums1 = z_func(sp);
    vector<int> nums2 = z_func(ps);
    for (int i = 0; i < n; i++){
        if ((nums2[i + n + 1] + nums1[2 * n - i + 1]) == n){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}