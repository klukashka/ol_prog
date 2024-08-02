#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
    
double polar_angle(double x, double y){
    double angle = atan2(y, x);
    return angle;
}

struct info{
    double angle;
    int x, y;
};

bool compare(info a1, info a2){
    if (a1.angle != a2.angle){
        return a1.angle > a2.angle;
    } else {
        return false;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<info> v(n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[i] = {polar_angle(x, y), x, y};
    }
    sort(v.begin(), v.end(), compare);
    ll square = 0;
    ll last_x = 0, last_y = 0;
    for (int i = 0; i < n; i++){
        square += 2 * v[i].x * last_y + v[i].y * v[i].x;
        last_x += v[i].x;
        last_y += v[i].y;
    }
    cout << square << '\n';
}