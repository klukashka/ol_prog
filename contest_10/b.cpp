#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(7);
    cout << fixed;
    double a, b, c, r1, r2, r3;
    cout << "? 0" << endl;
    cin >> r1;
    fflush(stdout);
    cout << "? 90" << endl;
    cin >> r2;
    fflush(stdout);
    cout << "? -90" << endl;
    cin >> r3;
    fflush(stdout);
    a = sqrt(r1 * r1 + r2 * r2);
    b = r2 + r3;
    c = sqrt(r3 * r3 + r1 * r1);
    double p = (a + b + c) / 2;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    cout << '!' << (a * b * c) / (4 * s) << '\n';
    fflush(stdout);
} 