#include <iostream>
#include <istream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

void num_reverse(vector<bool>& num, int from, int how_many){
    for (int i = from; i < from + how_many; i++){
        num[i] = num[i] ^ 1;
    }
}

void print_bin(vector<bool> num, int n){
    for (int i = 0; i <= n; i++){
        cout << num[i];
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    vector<bool> s, s_original, to_change;
    while (t--){
        // num will be reversed s
        cin >> n;
        s.resize(n);
        char val;
        for (int i = 0; i < n; i++){
            cin >> val;
            if (val == '1'){
                s[i] = 1;
            } else if (val == '0'){
                s[i] = 0;
            } else {
                cout << "ERROR\n";
            }
        }
        // print_bin(s_original, n);
        // cout << "   - s\n";
        bool good_k = false;
        for (int k = n; k > 1; k--){
            good_k = true;
            int counter = 0;
            to_change.assign(n+1, 0);
            for (int i = 0; i <= n-k; i++){
                // print_bin(to_change, n);
                // cout << k << " -k   " << i << " i  " << s[i] << " s[i]  "<< counter << " counter   - iteration begin\n";
                counter = counter ^ to_change[i];
                if (!(s[i] ^ counter)){
                    to_change[i + k] = 1;
                    counter = counter ^ 1;
                }
                // print_bin(to_change, n);
                // cout << k << " -k   " << i << " i  " << s[i] << " s[i]  "<< counter << " counter   - iteration end\n";
            }
            for (int i = n-k + 1; i < n; i++){
                // cout << k << " -k   " << i << " i  " << s[i] << " s[i]  "<< counter << " counter   - iteration begin\n";
                counter = counter ^ to_change[i];
                if (!(s[i] ^ counter)){
                    good_k = false;
                    break;
                }
                // cout << k << " -k   " << i << " i  " << s[i] << " s[i]  "<< counter << " counter   - iteration end\n";
            }
            if (good_k){
                cout << k << "\n";
                break;
            }
        }
        if (!good_k){
            cout << 1 << "\n";
        }
    }
}
// 00100 0
// 00110 0
// 00110 0
// 00