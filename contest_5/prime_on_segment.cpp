#include <iostream>
#include <vector>

using namespace std;

bool prime(int a){
    for (int i = 2; i*i <= a; i++){
        if (a % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, mx_r = 0;
    cin >> t;
    for (int i = 0; i < t; i++){
        int l ,r;
        cin >> l >> r;
        bool flag = false;
        for (int j = l; j <= r; j++){
            if (prime(j)){
                cout << j << endl;
                flag = true;
                break;
            }
        }
        if (!flag){
            cout << -1 << endl;
        }
    }
    // vector<ab> lines(t);
    // for (int i = 0; i < t; i++){
    //     int l, r;
    //     cin >> l >> r;
    //     ab line;
    //     line.a = l;
    //     line.b = r;
    //     if (r > mx_r){
    //         mx_r = r;
    //     }
    //     lines[i] = line;
    // }
    // vector<bool> is_prime(mx_r + 1, 1);
    // for (int i = 2; i <= mx_r; i++){
    //     if (is_prime[i]){
    //         for (int j = i * 2; j <= mx_r; j = j + i){
    //             is_prime[j] = 0;
    //         }
    //     }
    // }
    // for (int i = 0; i < t; i++){
    //     bool flag = false;
    //     for (int j = lines[i].a; j <= lines[i].b; j++){
    //         if (is_prime[j]){
    //             cout << j << endl;
    //             flag = true;
    //             break;
    //         }
    //     }
    //     if (!flag){
    //         cout << -1 << endl;
    //     }
    // }
}