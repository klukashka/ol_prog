#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n ; i++){
            cin >> a[i];
        }
        int cap = n;
        vector<int> dp_left(cap);
        vector<int> dp_right(cap);
        int ships_left, ships_right, ans = 0;
        int left_left, right_left;
        dp_left[0] = a[0];
        for (int i = 1; i < cap; i++){
            dp_left[i] = dp_left[i-1] + a[i];
        }
        dp_right[0] = a[n-1];
        for (int i = 1; i < cap; i++){
            dp_right[i] = dp_right[i - 1] + a[n - i - 1];
        }
        if (k % 2 == 1){
            ships_left = upper_bound(dp_left.begin(), dp_left.end(), k/2 + 1) - dp_left.begin();
            left_left = k/2 + 1 - dp_left[max(0, ships_left-1)];
            if (left_left < 0){
                left_left = a[0];
            }
            ships_right = upper_bound(dp_right.begin(), dp_right.end(), k/2) - dp_right.begin();
            right_left = k/2 - dp_right[max(0, ships_right-1)];
            if (right_left < 0){
                right_left = a[n-1];
            }
        } else {
            ships_left = upper_bound(dp_left.begin(), dp_left.end(), k/2) - dp_left.begin();
            left_left = k/2 - dp_left[max(0, ships_left-1)];
            if (left_left < 0){
                left_left = a[0];
            }
            ships_right = upper_bound(dp_right.begin(), dp_right.end(), k/2) - dp_right.begin();
            right_left = k/2 - dp_right[max(0, ships_right-1)];
            if (right_left < 0){
                right_left = a[n-1];
            }
        }
        ans = ships_left + ships_right;
        if (ans < n){
            if (ships_left + ships_right == n-1){
                if (left_left + right_left >= a[max(0, ships_left)]){
                    ans++;
                }
            }
        } else {
            ans = n;
        }
        // for (int i = 0; i < dp_left.size(); i++){
        //     cout << dp_left[i] << ' ';
        // } cout << " - dp_left\n";
        // for (int i = 0; i < dp_right.size(); i++){
        //     cout << dp_right[i] << ' ';
        // } cout << " - dp_right" << "     " << ships_left << " ships_left " << ships_right << " ships_right\n";
        // cout << left_left << " left_left  " << right_left << " right_left\n";
        cout << ans << '\n';
    }
}