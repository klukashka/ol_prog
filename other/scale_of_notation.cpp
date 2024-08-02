#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    string n;
    cin >> a >> b >> n;
    vector<int> digits(n.size());

    for (int i = 0; i < n.size(); i++){
        if ('0' <= n[i] && n[i] <= '9'){
            digits[i] = n[i] - '0';
        } else {
            digits[i] = n[i] - 'a' + 10;
        }
    }
    // for (int i = 0; i < n.size(); i++){
    //     cout << digits[i];
    // }
    // cout << '\n';

    ll number = 0;
    ll base = 1;
    for (int i = digits.size() - 1; i >= 0; i--){
        number += digits[i] * base;
        base *= a;
    }
    //cout << number << '\n';

    if (a == b){
        cout << n << '\n';
    } else if (b < 10){
        vector<int> answer;
        if (number == 0){
            cout << 0 << '\n';
        }
        while (number > 0){
            int left = number % b;
            answer.push_back(left);
            number /= b;
        }
        for (int i = answer.size() - 1; i >= 0; i--){
            cout << answer[i];
        }
        cout << '\n';
    } else {
        vector<char> answer;
        if (number == 0){
            cout << 0 << '\n';
        }
        while (number > 0){
            int left = number % b;
            if (left < 10){
                answer.push_back(left + '0');
            } else {
                answer.push_back(left - 10 + 'a');
            }
            number /= b;
        }
        for (int i = answer.size() - 1; i >= 0; i--){
            cout << answer[i];
        }
        cout << '\n';
    }
}