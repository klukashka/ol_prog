#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int million_number = 15485863;
    long long int sm = 0;
    m -= n;
    n--;
    vector<bool> is_prime(million_number + 1, 1);
    for (int i = 2; i <= million_number; i++){
        if (is_prime[i]){
            if (n == 0){
                sm += i;
                if (m == 0){
                    break;
                } else {
                    m--;
                }
            } else {
                //cout << i << " " << n << endl;
                n--;
            }
            for (int j = i * 2; j < million_number + 1; j = j + i){
                is_prime[j] = 0;
            }
        }
    }
    cout << sm << endl;
}