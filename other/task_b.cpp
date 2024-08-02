#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        v[i] = num;
        sort(v.begin(), v.begin() + i + 1);
        cout << v[i / 2] << endl;
    }
}