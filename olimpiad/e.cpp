#include <bits/stdc++.h>

using namespace std;

string int_to_roman(int a)
{
    string ans;
    string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    ans = M[a/1000]+C[(a%1000)/100]+X[(a%100)/10]+I[(a%10)];
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> roman_numbers(4000);
    for (int i = 1; i < 4000; i++){
        roman_numbers[i] = int_to_roman(i);
    }
    sort(roman_numbers.begin(), roman_numbers.end());

    vector<char> nums;
    nums = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> value;
    value = {1, 5, 10, 50, 100, 500, 1000};
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        int number = 0;
        for (int j = 0; j < s.size(); j++){
            int now, next;
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] == s[j]){
                    now = i;
                }
                if (nums[i] == s[j + 1]){
                    next = i;
                }
            }
            if (now >= next){
                number += value[now];
            } else {
                number -= value[now];
            }
        }
        // cout << number << '\n';
        cout << roman_numbers[number] << '\n';
    }
}