#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
using piv = pair<ll, vector<int>>;
#define all(x) x.begin(), x.end()

bool compare(const int& a, const int& b){
    return a <= b;
}

    
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
        vector<int> sum_of_pairs(arr_size - 1);
        for (int j = 0; j < arr_size - 1; j++){
            sum_of_pairs[j] = a[dp[i-1].second[j]] + a[dp[i-1].second[j+1]];
        }
        vector<ll> sum_we_can_lose(arr_size);
        ll cur_sm = 0;
        for (int j = 0; j < arr_size; j++){
            sum_we_can_lose[j] = cur_sm;
            cur_sm += a[dp[i-1].second[j]];
        }
        int good_ind = lower_bound(sum_of_pairs.begin(), sum_of_pairs.end(), elem, compare) - sum_of_pairs.begin();

        if (sum_we_can_lose[good_ind] < elem){
            vector<int> new_arr;
            for (int k = good_ind; k < arr_size; k++){
                new_arr.push_back(dp[i-1].second[k]);
            }
            new_arr.push_back(i);
            dp[i] = {dp[i-1].first + a[i] - sum_we_can_lose[good_ind], new_arr};
        } else {
            dp[i] = dp[i-1];
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