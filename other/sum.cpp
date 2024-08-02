#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string summa(string s1, string s2){
    int ind = s1.find('.');
    string str11 = s1.substr(0, ind);
    string str12 = s1.substr(ind + 1, 15);
    // cout << str11 << '.' << str12 << '\n';
    ind = s2.find('.');
    string str21 = s2.substr(0, ind);
    string str22 = s2.substr(ind + 1, 15);
    // cout << str21 << '.' << str22 << '\n';

    string s2_res = "";
    int additional = 0;
    for (int i = 14; i >= 0; i--){
        int sum = (str12[i] - '0') + (str22[i] - '0') + additional;
        additional = sum / 10;
        sum = sum % 10;
        char digit = char(sum + '0');
        s2_res = digit + s2_res;
    }
    ll s11_res = stoll(str11);
    ll s21_res = stoll(str21);
    // cout << s21_res << " " << str21 << " s21_res\n";
    ll s1_res = s11_res + s21_res + additional;
    string s_res = to_string(s1_res) + ".";
    // cout << s_res << " s_res\n";
    return s_res + s2_res;
}

int main(){
    string s;
    string sum;
    cin >> sum;
    while (cin >> s){
        sum = summa(sum, s);
    }
    cout << sum << "\n";
}