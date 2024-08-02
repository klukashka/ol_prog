#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ofstream file;
    file.open("primes.out");
    for (int i = 1e9; i < 1e15; i++){
        bool flag = true;
        for (int j = 2; j*j <= i; j++){
            if (i % j == 0){
                flag = false;
                break;
            }
        }
        if (flag){
            file << i << ' ';
        }
    }
}