#include <iostream>

using namespace std;

int f(int a, int b){
    if (a % 2 == 1 && b % 2 == 1){
        return 0;
    }
    if (a == b){
        return 2;
    }
    if (a == 1){
        if (b % 2 == 0){
            return 1;
        } else {
            return 0;
        }
    }
    if (b == 1){
        if (a % 2 == 0){
            return 1;
        } else {
            return 0;
        }
    }
    if (a % 2 == 0){
        if (b % 2 == 0){
            return 2;
        }
        if (b < a){
            return 1;
        }
        return 3;
    }
    if (b < a){
        return 3;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--){
        int a, b;
        cin >> a >> b;
        // ans = ans ^ f(a, b);
        // cout << a << ' ' << b << ' ';
        // cout << f(a, b) << " f(a, b)\n";
        ans = ans ^ f(a, b);
        // cout << ans << " ans\n";
    }
    if (ans > 0){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
    // for (int i = 1; i <= 15; i++){
    //     for (int j = 1; j <= 15; j++){
    //         if (i % 2 == 1 && j % 2 == 1){
    //             cout << 0 << ' ';
    //         } else { 
    //             cout << f(i, j) << ' ';
    //         }
    //     }
    //     cout << '\n';
    // }
}