#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
    
using namespace std;
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long int> v(n);
    if (n < 3){
        cout << 0;
    } else {
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        long long int sm = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 2; i++){
            for (int j = i + 1; j < n - 1; j++){
                long long int low = lower_bound(v.begin() + j + 1, v.end(), v[i] + v[j]) - v.begin();
                sm += low - j - 1;
            }
        }
        cout << sm << endl;
    }
}