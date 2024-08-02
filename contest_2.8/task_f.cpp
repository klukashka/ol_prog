#include <bits/stdc++.h>
    
using namespace std;

// int f(int n, int m){
//     if (n == 1){
//         if (m % 2 == 0){
//             return 1;
//         }
//         return 2;
//     }
//     if (m == 1){
//         if (n % 2 == 0){
//             return 1;
//         }
//         return 2;
//     }
//     if (n == m){
//         if (n % 2 == 1){
//             return 2;
//         }
//         return 1;
//     }
//     if (n % 2 == 0){
//         if (n )
//     } else {
//         if ()
//     }
// }
    

    
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin >> n >> m;
    if (n % 2 == 1 && m % 2 == 1){
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
    }
}