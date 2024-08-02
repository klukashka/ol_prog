#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

// vector<int> primes = {2, 3, 4, 5, 7, 9, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 121, 127, 131, 137, 139, 149, 151, 157, 163, 167, 169, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 289, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 361, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 529, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 841, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 961, 967, 971, 977, 983, 991, 997};

// bool prime(int x){
//     for (int i = 2; i * i < x; i++){
//         if (x % i == 0){
//             return false;
//         }
//     }
//     return true;
// }

void solve(){
    // for (int i = 2; i <= 1000; i++){
    //     if (prime(i)){
    //         cout << i << ", ";
    //     }
    // }
    // cout << '\n';
    int x;
    cin >> x;
    int mx_val = 1;
    int mx = 1;
    for (int i = 1; i < x; i++){
        int val = __gcd(x, i) + i;
        if (val > mx_val){
            mx_val = val;
            mx = i;
        }
    }
    cout << mx << '\n';
    // if (x == 1){
    //     cout << 2 << '\n';
    //     return;
    // }
    // if (x == 2){
    //     cout << 3 << '\n';
    //     return;
    // }
    // // int x_ind = lower_bound(all(primes), x) - primes.begin();
    // for (int i = 0; i < primes.size(); i++){
    //     if (primes[i] >= x){
    //         cout << primes[i-1] + 1 << '\n';
    //         return;
    //     }

    // }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}