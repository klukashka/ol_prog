#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()

void pr(vector<int> nums){
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << ' ';
    }
    cout << '\n';
}

int find_largest_power(int k){
    int ans = 0;
    for (int i = 0; i < 32; i++){
        if (k & (1 << i)){
            ans = (1 << i);
        }
    }
    return ans;
}

void fill_with_nulls(vector<int>& nums){
    for (int i = 2; i < nums.size(); i++){
        nums[i] = 0;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    if (n == 1){
        cout << k << '\n';
        return;
    }
    vector<int> nums(n);
    int ans;
    ans = find_largest_power(k);
    // cout << ans << " ans\n";
    nums[0] = ans - 1;
    nums[1] = k - nums[0];
    fill_with_nulls(nums);
    pr(nums);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}