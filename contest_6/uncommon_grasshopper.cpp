#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, sm = 0;
    cin >> n >> m;
    vector<int> res(m + 1);
    res[1] = 1;
    for (int i = 1; i <= m / 2; i++){
        for (int j = 2 * i; j <= m; j = j + i){
            res[j] = (res[j] + res[i]) % 1000000007;
        }
    }
    for (int i = n; i <= m; i++){
        sm = (sm + res[i]) % 1000000007;
    }
    cout << sm << '\n';
}