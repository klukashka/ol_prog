#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct coordinate{
    ll x1, y1, x2, y2;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<coordinate> coordinates(n);
    for (int i = 0; i < n; i++){
        cin >> coordinates[i].x1 >> coordinates[i].y1 >> coordinates[i].x1 >> coordinates[i].y2;
    }
    
}