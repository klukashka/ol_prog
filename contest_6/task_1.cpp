#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> v(n + 1, 0);
    v[0] = 1;
    for (int i = 0; i < m; i++){
        int m_i;
        cin >> m_i;
        v[m_i] = -1;
    }
    if (n > k){
        for (int i = 1; i < k; i++){
            if (v[i] != -1){
                for (int j = 0; j < i; j++){
                    if (v[j] != -1){
                        v[i] = (v[i] + v[j]) % 1000000007;
                    }
                }
            }
        }
        for (int i = k; i < n + 1; i++){
            if (v[i] != -1){
                for (int j = 1; j <= k; j++){
                    if (v[i - j] != -1){
                        v[i] = (v[i] + v[i - j]) % 1000000007;
                    }
                }
            }
        }
        cout << v[n] << '\n';
    } else {
        for (int i = 1; i < n + 1; i++){
            if (v[i] != -1){
                for (int j = 0; j < i; j++){
                    if (v[j] != -1){
                        v[i] = (v[i] + v[j]) % 1000000007;
                    }
                }
            }
        }
        cout << v[n] << '\n';
    }
}