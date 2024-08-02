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
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sg(n+1); // solutions for the ribbon of length i
    sg[0] = 0;
    for (int i = 1; i <= n; i++){
        vector<int> u;
        for (int j = 1; j <= i; j++){ //putting cross on j and looking for answer from left and right
            u.push_back(sg[max(0, j-2)]^sg[max(0, i-j-1)]); // xoring solutions of j-2 and i-j+1 cells
        }
        sg[i] = mex(u);
    }
    if (sg[n] > 0){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}