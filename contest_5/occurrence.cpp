#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

int gcd(int ind1, int ind2, vector<int> &m){
    int ans = m[ind1];
    for (int i = ind1 + 1; i <= ind2; i++){
        ans = __gcd(ans, m[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    long long int ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        ans += v[i];
    }
    for (int k = 1; k < n; k++){
        if (k < 21){
            for (int j = 0; j < n - k; j++){
                ans += gcd(j, j + k, v);
            }
        } else {
            for (int j = 0; j < n - k; j++){
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
}