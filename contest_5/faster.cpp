#include <bits/stdc++.h>
    
using namespace std;
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M = 40000000;
    vector<bool> v(M + 1, 1);
    vector<short> count(M + 1);
    v[1] = 0;
    count[1] = 0;
    for (int i = 2; i <= M; i++){
        if (v[i]){
            for (int j = 2 * i; j <= M; j += i){
                v[j] = 0;
                count[j] += 1;
            }
        }
    }
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        if (v[num]){
            cout << "Prime" << '\n';
        } else {
            cout << count[num] << '\n';
        }
    }
}