#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
using ll = long long int;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    short n;
    cin >> n;
    vector<vector<short>> v(n + 1);
    v[1] = {1};
    v[2] = {2, 3};
    for (short i = 3; i <= n; i++){
        v[i].push_back(i);
        for (short j = 0; j < v[i - 1].size(); j++){
            v[i].push_back(v[j] + 1);
            v[i].push_back(v[j] - 2)
        }
    }
}