#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<char> init_word(n);
    for (int i = 0; i < n; i++){
        cin >> init_word[i];
    }
    int init_set = 0;
    vector<char> short_word;
    for (int i = 0; i < n; i++){
        int letter = 1 << (init_word[i] - 'a');
        if ((init_set | letter) != init_set){
            init_set = init_set | letter;
            short_word.push_back(init_word[i]);
        }
    }
    int short_n = short_word.size();
    sort(short_word.begin(), short_word.end());
    for (int i = 0; i < n; i++){
        char letter = init_word[i];
        for (int j = 0; j < short_n; j++){
            if (short_word[j] == letter){
                cout << short_word[short_n - j-1];
                break;
            }
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
