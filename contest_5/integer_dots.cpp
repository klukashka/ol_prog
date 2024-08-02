#include <iostream>
#include <numeric>

using namespace std;
using ll = long long int;

int gcd(int a, int b){
    if (a != 0 && b != 0){
       return gcd(a, b);
    } else if (a == 0){
        return b;
    } else {
        return a;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2 > x1){
            if (y2 > y1){
                cout << gcd(x2 - x1, y2 - y1) + 1 << endl;
            } else {
                cout << gcd(x2 - x1, y1 - y2) + 1<< endl;
            }
        } else {
            if (y2 > y1){
                cout << gcd(x1 - x2, y2 - y1) + 1 << endl;
            } else {
                cout << gcd(x1 - x2, y1 - y2) + 1 << endl;
            }
        }
    }
}