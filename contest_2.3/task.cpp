#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
using piv = pair<ll, vector<int>>;
#define all(x) x.begin(), x.end()

    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream in_file;
    in_file.open("joke.in");
    int n;
    in_file >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        in_file >> a[i];
    }
    sort(all(a));
    
    vector<piv> dp(n);
    dp[0] = {a[0], {0}};
    dp[1] = {a[0] + a[1], {0, 1}};
    for (int i = 2; i < n; i++){
        int arr_size = dp[i-1].second.size();
        int elem = a[i];
        ll cur_sm = 0; // how much we can lose
        bool found = false;
        for (int j = 1; j < arr_size; j++){
            if (a[dp[i-1].second[j-1]] + a[dp[i-1].second[j]] > elem){
                if (cur_sm < elem){
                    vector<int> new_arr;
                    for (int k = j-1; k < arr_size; k++){
                        new_arr.push_back(dp[i-1].second[k]);
                    }
                    new_arr.push_back(i);
                    dp[i] = {dp[i-1].first + a[i] - cur_sm, new_arr};
                    found = true;
                    break;
                } else {
                    dp[i] = dp[i-1];
                    found = true;
                    break;
                }
            }
            cur_sm += a[dp[i-1].second[j-1]];
        }
        if (!found){ // last chance
            if (a[dp[i-1].second[arr_size-1]] + a[i] > cur_sm){
                dp[i] = {a[dp[i-1].second[arr_size-1]] + a[i], {dp[i-1].second[arr_size-1], i}};
            } else {
                dp[i] = dp[i-1];
            }
        }

    }
    // for (int i = 0; i < a.size(); i++){
    //     cout << a[i] << ' ';
    // }
    // cout << "\n\n";

    // for (int i = 0; i < n; i++){
    //     cout << dp[i].first << "   ";
    //     for (int j = 0; j < dp[i].second.size(); j++){
    //         cout << dp[i].second[j] + 1 << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    cout << dp[n-1].first << " - ans\n";
}