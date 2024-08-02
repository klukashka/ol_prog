#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

double polar_angle(double x, double y){
    double angle = atan2(y, x);
    if (angle < 0){
        return 2 * pi + angle;
    } else {
        return angle;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout.precision(7);
    cout << fixed;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        double angle = polar_angle(x, y);
        cout << angle << '\n';
    }
}