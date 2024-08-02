#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> digits(10, 0);
        if (n > 1){
            for(int j = 9; j >= 2; j--){
                while (n % j == 0){
                    digits[j]++;
                    n = n / j;
                }
            }
            if (n == 1){
                for (int j = 0; j < 10; j++){
                    while (digits[j] != 0){
                        cout << j;
                        digits[j]--;
                    }
                }
                cout << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (n == 1){
            cout << 1 << '\n';
        } else {
            cout << 10 << '\n';
        }
        digits.clear();
    }
}