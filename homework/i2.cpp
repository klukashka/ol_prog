#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

int f(vector<int> &m, vector<int> &c, int &w, int &n){
    vector<int> dp_prev(w + 1, 0);
    vector<int> dp_curr(w + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= w; j++){
            dp_curr[j] = dp_prev[j];
            if (j - m[i - 1] >= 0){
                dp_curr[j] = max(dp_prev[j], dp_prev[j - m[i - 1]] + c[i - 1]);
            }
        }
        swap(dp_curr, dp_prev);
    }
    return dp_prev[w];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vector<int> m(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        cin >> m[i];
    }
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    cout << f(m, c, w, n) << '\n';
}