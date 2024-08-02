#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, a, b;
        cin >> n >> a >> b;
        if (2 * a > b){
            cout << (n / 2) * b + (n % 2) * a << '\n';
        } else {
            cout << n * a << '\n';
        }
    }
}