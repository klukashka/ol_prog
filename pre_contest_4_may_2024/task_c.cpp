#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;

    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k > 1){
        cout << "1 A A\n";
        k -= 2;
    } else if (k > 0){
        cout << "1 A S\n";
        k--;
    } else {
        cout << "1 S S\n";
    }
    for (int i = 2; i <= n; i++){
        cout << i << ' ' << i-1 << ' ';
        if (k > 0){
            cout << "A";
            k--;
        } else {
            cout << "S";
        }
        cout << '\n';
    }
}