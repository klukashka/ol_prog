#include <bits/stdc++.h>

using namespace std;

vector<int> z_func(const string& s){
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        z[i] = max(0, min(z[i-l], r-i));
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]){
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
    cin >> s;
    p = s;
    int n = s.size();
    reverse(p.begin(), p.end());
    sp = s + '$' + p;
    vector<int> nums = z_func(sp);
    int ln = 2 * n + 1;
    for (int i = n + 1; i < ln; i++){
        if (nums[i] == ln - i){
            cout << ln - i << '\n';
            return 0;
        }
    }
}