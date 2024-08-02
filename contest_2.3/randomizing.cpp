#include <bits/stdc++.h>

using namespace std;

int main(){

    ofstream out_file;
    out_file.open("joke.in");
    int n = 1e4;
    int mod = 1e9;
    out_file << n << '\n';
    for (int i = 0; i < n; i++){
        out_file << rand() % mod <<  ' ';
    }
    // vector<int> v = {3};
    // auto lower = lower_bound(v.begin(), v.end(), 3, compare);
    // cout << *lower  << ' ' << lower - v.begin() << '\n';
}