#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        int left_min = a[i];
        int right_min = a[i];
        int c = i-1;
        while (c >= 0){
            left_min = min(max(a[c], abs(a[c] - a[c+1])), left_min);
            if (left_min > a[c]){
                break;
            }
            c--;
        }
        c = i+1;
        while (c < n){
            right_min = min(max(a[c], abs(a[c] - a[c-1])), right_min);
            if (right_min > a[c]){
                break;
            }
            c++;
        }
        ans[i] = min(a[i], min( left_min, right_min));
        // cout << left_min << ' ' << right_min << "   " << i << '\n';
    }
    for (int v : ans){
        cout << v << ' ';
    }
    cout << '\n';
}