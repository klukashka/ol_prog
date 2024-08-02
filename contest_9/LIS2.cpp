#include <bits/stdc++.h>

using ll = long long;
using namespace std;
int inf = 1000000000;

struct info{
    int value, ind;
};

bool compare(info a, info b){
    return a.value < b.value;
}

vector<int> LIS(vector<int> &a, int &n){
    vector<info> dp(n, {inf, -1});
    vector<int> prevs(n, -1);
    dp[0] = {a[0], 0};

    for (int i = 1; i < n; i++){
        int found_ind = lower_bound(dp.begin(), dp.end(), info{a[i], -1}, compare) - dp.begin();
        dp[found_ind] = {a[i], i};
        if (found_ind > 0){
            prevs[i] = dp[found_ind-1].ind;
        } else {
            prevs[i] = -1;
        }
    }
    int max_ind;
    for (int i = n - 1; i >= 0; i--){
        if (dp[i].value < inf){
            max_ind = i;
            break;
        }
    }
    vector<int> ans;
    ans.push_back(dp[max_ind].ind);
    int curr_ind = prevs[dp[max_ind].ind];
    while (curr_ind != -1){
        ans.push_back(curr_ind);
        curr_ind = prevs[curr_ind];
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++){
            cin >> v[j];
        }
        vector<int> ans = LIS(v, n);
        cout << ans.size() << '\n';
        for (int j = ans.size() - 1; j >= 0; j--){
            cout << ans[j] + 1 << " ";
        }
        cout << '\n';
    }
}