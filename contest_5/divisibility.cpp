#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string num;
    cin >> num;
    int res = 0;
    for (int i = 0; i < num.length(); i++){
        int a = num[i] - '0';
        res += a;
        res = res % 97;
        res = res * 10;
    }
    if (res == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}