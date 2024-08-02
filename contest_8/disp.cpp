#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        set<ll> st;
        st.insert(v[0]);
        int l = 0, r = 0;
        int mx = 1;
        while (r < n-1){
            if (l != r){
                if (st.size() < (r - l  + 1)){
                    if (v[l] != v[r]){
                        st.erase(v[l]);
                    }
                    l++;
                } else{
                    r++;
                    st.insert(v[r]);
                }
            } else {
                r++;
                st.insert(v[r]);
            }
            if (mx < st.size()){
                mx = st.size();
            }
            // vector<ll> h(st.begin(), st.end());
            // for (int i = 0; i < h.size(); i++){
            //     cout << h[i] << ' ';
            // }
            // cout << '\n';
        }
        cout << mx << '\n';
    }
}
