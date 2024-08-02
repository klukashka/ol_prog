#include <iostream>

using namespace std;

int main(){
    long long int n, a, prev, mx1 = 0, mx2 = 0;
    cin >> n >> prev;
    for (int i = 1; i <= n; i++){
        a = (prev * 5) % 1000000007;
        if (a > mx1){
            mx2 = mx1;
            mx1 = a;
        } else if (a < mx1 && a > mx2){
            mx2 = a;
        }
        prev = a;
    }
    cout << mx2 << " " << mx1 << endl;
}