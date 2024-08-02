#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(7);
    cout << fixed;
    double x, y;
    cin >> x >> y;
    double v1, v2, d;
    cin >> v1 >> v2 >> d;
    //double eps = 0.00000001;
    double x_low = 0, x_max = x;
    double x_mid = (x_low + x_max) / 2;
    double sin_a = x_mid / sqrt(x_mid * x_mid + d * d);
    double sin_b = abs(x - x_mid) / sqrt((x - x_mid) * (x - x_mid) + (y - d) * (y - d));
    double expression = sin_a / sin_b;
    double n = v1 / v2;
    //cout << expression << ' ' << n << '\n';
    //int c = 0;
        for (int i = 0; i < 100; i++){
            // if (c == 10){
            //     break;
            // }
            //cout << x_mid << '\n';
            if (expression / n > 1){
                x_max = x_mid;
            } else {
                x_low = x_mid;
            }
            x_mid = (x_low + x_max) / 2;
            sin_a = x_mid / sqrt(x_mid * x_mid + d * d);
            sin_b = abs(x - x_mid) / sqrt((x - x_mid) * (x - x_mid) + (y - d) * (y - d));
            expression = sin_a / sin_b;
            // c++;
        }
        //cout << c << '\n';
        cout << x_mid << '\n';
} 