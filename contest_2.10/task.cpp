#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v = {5};
    cout << lower_bound(v.begin(), v.end(), 10) - v.begin() << '\n';
}