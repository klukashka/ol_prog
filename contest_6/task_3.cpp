#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long int;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[1] = 0;
    v[2] = 2;
    v[3] = 3;
    for (int i = 4; i <= n; i++){
        if (i % 2 == 0){
            if (i % 3 == 0){
                v[i] = min(v[i - 1], min(v[i / 2], v[i / 3]));
            }
            else {
                v[i] = min(v[i - 1], v[i / 2]);
            }
        } else {
            if (i % 3 == 0){
                v[i] = min(v[i - 1], v[i / 3]);
            }
            else {
                v[i] = v[i - 1];
            }
        }
        v[i] += i;
    }
    cout << v[n] << '\n';
}