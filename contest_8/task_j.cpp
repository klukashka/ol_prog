#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v_n(n);
    vector<int> v_m(m);
    vector<int> counter_n(101, 0);
    vector<int> counter_m(101, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++){
        cin >> v_n[i];
    }
    for (int i = 0; i < m; i++){
        cin >> v_m[i];
        counter_m[v_m[i]]++;
    }
    for (int i = 0; i < m; i++){
        counter_n[v_n[i]]++;
    }
    for (int i = 0; i < n - m; i++){
        bool good = true;
        for (int j = 0; j <= 100; j++){
            if (counter_n[j] != counter_m[j]){
                good = false;
                break;
            }
        }
        if (good){
            ans.push_back(i + 1);
        }
        counter_n[v_n[i]]--;
        counter_n[v_n[i + m]]++;
    }

    bool good = true;
    for (int j = 0; j <= 100; j++){
        if (counter_n[j] != counter_m[j]){
            good = false;
            break;
        }
    }
    if (good){
        ans.push_back(n - m + 1);
        }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}