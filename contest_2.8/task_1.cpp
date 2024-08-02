#include <bits/stdc++.h>

using namespace std;

int mex(const vector<int>& a){
    int n = a.size();
    vector<int> been(n+1);
    for (int i = 0; i < n; i++){
        if (a[i] <= n){
            been[a[i]] = 1;
        }
    }
    for (int i = 0; i <= n; i++){
        if (!been[i]){
            return i;
        }
    }
    return n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    vector<int> sg(1e5+1);
    int a, k;
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a >> k;
        if (a >= k){
            ans = ans ^ (a % (k+1));
        } else {
            ans = ans ^ a;
        }
    }
    if (ans > 0){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}