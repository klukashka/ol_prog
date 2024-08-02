#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string init;
    getline(cin, init);
    vector<string> words;
    int begin_word = 0;
    // string token;
    // char delim = ' ';
    // while (getline(cin, token, delim)){
    //     words.push_back(token);
    // }
    for (int i = 1; i < init.size(); i++){
        if (init[begin_word] == ' '){
            begin_word = i;
            continue;
        }
        if (init[i] == ','){
            string new_word = init.substr(begin_word, i-begin_word+1);
            if (new_word == ","){
                words[words.size()-1] = words[words.size()-1].append(new_word);
                begin_word = i + 1;
                continue;
            }
            words.push_back(new_word);
            begin_word = i + 1;
        }
        if (init[i] == ' '){
            string new_word = init.substr(begin_word, i-begin_word);
            if (new_word == ","){
                words[words.size()-1] = words[words.size()-1].append(new_word);
                begin_word = i + 1;
                continue;
            }
            words.push_back(new_word);
            begin_word = i + 1;
        }
    }
    if (begin_word < init.size()){
        string new_word = init.substr(begin_word, init.size()-begin_word);
        if (new_word == ","){
            words[words.size()-1] = words[words.size()-1] + new_word;
        } else {
            words.push_back(new_word);
        }
    }
    // for (string s : words){
    //     cout << s << ";\n";
    // }

    int longest = 0;
    for (int i = 0; i < words.size(); i++){
        int sz = words[i].size();
        longest = max(sz - (words[i][words[i].size()-1] == ','), longest);
    }
    int ln = longest*3;
    // cout << longest << "\n\n\n";
    int cur_len = words[0].size();
    int i = 1;
    cout << words[0];
    while (i < words.size()){
        if (words[i][words[i].size()-1] != ','){
            if (cur_len != 0){
                if (words[i].size() + cur_len + 1 <= ln){
                    cout << ' ' << words[i];
                    cur_len += words[i].size() + 1;
                } else {
                    cout << '\n';
                    cur_len = 0;
                    continue;
                }
            } else {
                cout << words[i];
                cur_len += words[i].size();
            }
        } else if (words[i][words[i].size()-1] == ','){
            if (cur_len != 0){
                if (words[i].size() + cur_len + 1 < ln){
                    cout << ' ' << words[i];
                    cur_len += words[i].size() + 1;
                } else if (words[i].size() + cur_len == ln){
                    cout << ' ' <<words[i];
                    cout << '\n';
                    cur_len = 0;
                    continue;
                } else {
                    cout << '\n';
                    cur_len = 0;
                    continue;
                }
            } else {
                cout << words[i];
                cur_len += words[i].size();
            }
        } else {
            if (cur_len != 0){
                if (words[i].size() + cur_len + 1 <= ln){
                    cout << ' ' <<words[i];
                    cur_len += words[i].size() + 1;
                    break;
                } else {
                    cout << '\n';
                    cur_len = 0;
                    continue;
                }
            } else {
                cout << words[i];
                break;
            }
        }
        i++;
    }
    cout << '\n';
}