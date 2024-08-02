#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct coord{
    int a, b;
};

int solve(vector<coord>& v, int c){
    int 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<coord> v(n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> v[i].a >> v[i].b;
    }
    sort(v.begin(), v.end());
    ll res = 0;
    for (int i = 0; i < n; i++){
        res += solve(v, i);
    }
}