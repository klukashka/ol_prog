#include <bits/stdc++.h>
#include <tuple>
using namespace std;
using ll = long long int;

struct info{
    ll first, second;
};

bool compare(info a, info b){
    if (a.first != b.first){
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<info> v(2 * n);
    for (int i = 0; i < 2 * n; i = i + 2){
        cin >> v[i].first >> v[i + 1].first;
        v[i].second = 1;
        v[i + 1].second = -1;
    }

    sort(v.begin(), v.end(), compare);
    int sm = 0;
    int max_sm = 0;
    int max_num = 0;
    for (int i = 0; i < 2 * n; i++){
        sm += v[i].second;
        if (sm > max_sm){
            max_sm = sm;
            max_num = v[i].first;
        }
    }
    cout << max_sm << " " << max_num << '\n';
}