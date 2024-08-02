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

    vector<bool> is_square(5001, false);
    for (int i = 1; i*i <= 5000; i++){
        is_square[i * i] = true;
    }
    int n;
    cin >> n;
    vector<int> sg(n+1);
    sg[0] = 0;
    sg[1] = 1;
    if (n > 1){
        for (int i = 2; i <= n; i++){
            vector<int> u;
            for (int j = 1; j <= i; j++){
                if (is_square[j]){
                    u.push_back(sg[i-j]);
                }
            }

            sg[i] = mex(u);
            // cout << sg[i] << '\n';
        }
    }
    if (sg[n] > 0){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}