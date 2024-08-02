#include <bits/stdc++.h>

using namespace std;

char to_lower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    unordered_set<char> v;
    while (n--){
        cin >> s;
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            c = to_lower(c);
            v.insert(c);
        }
    }
    if (v.size() < 26){
        cout << "Fake\n";
    } else {
        cout << "Truth\n";
    }
}