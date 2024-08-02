#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++){
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<int> seq(n + k);
        for (int i = 0; i < seq.size(); i++){
            seq[i] = i;
        }
        int c1, c2, k_c;
        if (v[0] == seq[0]){
            c1 = 1;
            c2 = 1;
            k_c = 0;
        } else {
            c1 = 0;
            c2 = 1;
            k_c = 1;
        }
        while (k_c < k){
            if (v[c1] == seq[c2]){
                c2++;
                c1++;
            } else {
                if (v[c1] != v[c1 - 1]){
                    k_c++;
                    c2++;
                } else {
                    c1++;
                }
            }
        }
        cout << seq[c2 - 1] << '\n';
    }
}