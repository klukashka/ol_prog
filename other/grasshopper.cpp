#include <iostream>
#include <vector>
using namespace std;

int main(){
    int nn, kk;
    cin >> nn >> kk;
    for (int n = 1; n <= nn; n++){
        for (int k = 1; k <= kk; k++){
            vector<int> v(n + 1, 0);
            v[0] = 1;
            if (n > k){
                for (int i = 1; i < k; i++){
                    for (int j = 0; j < i; j++){
                        v[i] = (v[i] + v[j]) % 1000000007;
                    }
                }
                for (int i = k; i < n + 1; i++){
                    for (int j = 1; j <= k; j++){
                        v[i] = (v[i] + v[i - j]) % 1000000007;
                    }
                }
                cout << v[n] << " " << n << " " << k << endl;
            } else {
               for (int i = 1; i < n + 1; i++){
                    for (int j = 0; j < i; j++){
                        v[i] = (v[i] + v[j]) % 1000000007;
                    }
                }
                cout << v[n] << " " << n << " " << k << endl;
            }
        }
    }
}