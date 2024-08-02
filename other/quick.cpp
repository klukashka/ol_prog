#include <iostream>
#include <vector>
    
using namespace std;
    
int main(){
    long long int n, a, m, k, mod;
    cin >> n >> a >> m >> k >> mod;
    vector<long long int> cnt(mod, 0);
    long long int sm = 0;
    for (int i = 0; i < n; ++i){
        cnt[a] += 1;
        a = (a * m + k) % mod;
        
    }
    long long int counter = 0;
    long long int sum_first_n = 0;
    for (int i = 0; i < mod; i++){
        sum_first_n = counter * (counter + 1) / 2;
        sm += (i * ((cnt[i] + counter) * (cnt[i] + counter + 1) / 2 - sum_first_n)) % 1000000007;
        counter += cnt[i];
    }
    cout << sm % 1000000007 << endl;
}