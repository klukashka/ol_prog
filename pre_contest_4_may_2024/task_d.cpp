#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, ans;
    cin >> n >> k;
    if (n % 2 == 1){
        cout << "Knight\n";
    } else if(k >= n){
        cout << "Knight\n";
    } else {
        if (k == 1){
            cout << "AI\n";
        } else {
            int ans = 0;
            for (int i = k; i > 1; i--){
                if (i % 2 == 1){
                    continue;
                }
                if (n % i == 0 && (n / i) % 2 == 1){
                    ans = 1;
                    break;
                }
            }
            if (ans > 0){
                cout << "Knight\n";
            } else {
                cout << "AI\n";
            }
        }
    }
}