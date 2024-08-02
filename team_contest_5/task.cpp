#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n, t, m, x, y;
    cin >> n >> t >> m >> x >> y;
    t = t * 60;
    double time = (m / x + (n-m) / y);
    if (time > t){
        cout << (int)ceil((time - t) / 60) << '\n';
    } else {
        cout << 0 << '\n';
    }
}