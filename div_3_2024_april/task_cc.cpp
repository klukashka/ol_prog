#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    deque<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll mn;
    int counter = 0;
    while (a.size() > 1 && k > 0){
        mn = min(a.front(), a.back());
        if (k >= 2 * mn){
            a.front() -= mn;
            a.back() -= mn;
            k -= 2*mn;
        } else {
            a.front() -= (k/2);
            a.back() -= (k/2);
            if (k % 2 == 1){
                a.front()--;
            }
            k = 0;
        }
        if (a.front() == 0){
            a.pop_front();
            counter++;
        }
        if (a.back() == 0){
            a.pop_back();
            counter++;
        }
    }
    if (a.front() <= k && a.size()){
        counter++;
    }
    cout << counter << '\n';
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