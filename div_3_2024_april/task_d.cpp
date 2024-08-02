#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, m, k;
        cin >> n >> m >> k;
        int real_k = 0, result = 0;
        vector<int> input(n);
        unordered_map<int, int> a, b;
        int val;
        for (int i = 0; i < n; i++){
            cin >> input[i]; // reading a input
        }
        for (int i = 0; i < m; i++){
            a[input[i]]++; // prefilling first m values (first subsegment)
        }
        for (int i = 0; i < m; i++){
            cin >> val; // reading b input
            b[val]++;
        }

        // checking difference between first subsequence of a and vector b
        for (auto const& [key, val] : a){
            if (b[key] > 0){
                real_k += min(b[key], val);
            }
        }
        if (real_k >= k){
            result++;
        }
        int val_prev;
        // cout << real_k << " - k\n";
        for (int i = m; i < n; i++){
            val = input[i];
            a[val]++;
            if (b[val] > 0 && a[val] <= b[val]){
                real_k++;
            }
            val_prev = input[i-m];
            a[val_prev]--;
            if (b[val_prev] > 0 && a[val_prev] < b[val_prev]){
                real_k--;
            }
            if (real_k >= k){
                result++;
            }
            // cout << val << " val " << a[val] << " amount\n";
            // cout << val_prev << " val_prev " << a[val_prev] << " amount\n";
            // cout << real_k << " - k\n";
        }
        cout << result << '\n';
    }
}