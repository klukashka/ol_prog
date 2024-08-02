#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        res = res ^ a;
    }
    if (res > 0){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}