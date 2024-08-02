#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++){
    //     cin >> a[i];
    // }

    vector<int> divs(1e7+1);
    for (int v = 5; v <= 1e7; v++){
        divs[v] = v;
        for (int j = 2; j*j <= v; j++){
            if (v % j == 0){
                if (j != 2){
                    divs[v] = j;
                    break;
                } else {
                    divs[v] = min(v / j, divs[v]);
                }
            }
        }
    }
    divs[3] = 3;
    divs[4] = 4;
    // vector<bool> is_prime(1e7+1, true);
    // for (int i = 2; i <= 1e7; i++){
    //     for (int j = i; j <= 1e7; j = j + i){
    //         is_prime[j] = false;
    //     }
    // }
    ofstream file;
    file.open("out.out");
    for (int v : divs){
        file << divs[v] << ", ";
    }
    file << '\n';
}