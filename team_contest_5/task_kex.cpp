#include <bits/stdc++.h>
using namespace std;
using ll = long long;
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<ll> to_find(q);
    for (int i = 0; i < q; i++){
        cin >> to_find[i];
    }
    sort(v.begin(), v.end());
    sort(to_find.begin(), to_find.end());
    // vector<int> seq(n + to_find[q-1] + 1);
    // for (int i = 0; i < seq.size(); i++){
    //     seq[i] = i;
    // }
    // for (int i = 0; i < seq.size(); i++){
    //     cout << seq[i] << ' ';
    // } cout << '\n';
    ll c_over_v, c_over_numbers = 0, how_many_found, k_to_find = 0;
    if (v[0] == c_over_numbers){
        c_over_v = 1;
        c_over_numbers = 1;
        how_many_found = 0;
    } else {
        c_over_v = 0; // actually v iterator
        c_over_numbers = 1; // seq iterator
        how_many_found = 1; // how many found
        if (to_find[k_to_find] == how_many_found){
            cout << c_over_numbers-1 << ' ';
            k_to_find++;
        }
    }
    while (how_many_found != to_find[q-1]){
        // cout << how_many_found << ' ' << c_over_v << ' ' << c_over_numbers << ' ' << k_to_find << '\n';
        if (v[c_over_v] == c_over_numbers){
            c_over_numbers++;
            c_over_v++;
        } else {
            if (v[c_over_v] != v[c_over_v - 1]){
                if (to_find[k_to_find] - 1 == how_many_found){
                    while (to_find[k_to_find + 1] == to_find[k_to_find]){
                        cout << c_over_numbers << ' ';
                        k_to_find++;
                    }
                    cout << c_over_numbers << ' ';
                    k_to_find++;
                }
                how_many_found++;
                c_over_numbers++;
            } else {
                c_over_v++;
            }
        }
    }
    cout << '\n';
}