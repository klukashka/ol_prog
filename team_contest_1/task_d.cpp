#include <bits/stdc++.h>

using namespace std;

using dict_t = unordered_map<string, string>;
using counter_t = unordered_map<string, pair<long long, long long>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int text_len;
    cin >> text_len;

    vector<string> text;
    for (int i = 0; i < text_len; i++) {
        string buffer;
        cin >> buffer;
        text.push_back(buffer);
    }

    int words_count;
    dict_t dict;
    counter_t translations;

    cin >> words_count;

    for (int i = 0; i < words_count; i++) {
        string dutch, english, state;
        cin >> dutch >> english >> state;
        if (dict.find(dutch) == dict.end()) {
            translations[dutch] = pair<long long, long long>(0, 0); // correct and incorrect translation
            dict[dutch] = english;
        }
        if (state.compare("correct") == 0)
            translations[dutch].first++;
        else
            translations[dutch].second++;
    }

    vector<pair<long long, long long>> dp(text_len);
    dp[0] = translations[text[0]];

    for (int i = 1; i < text_len; i++) {
        pair<long long, long long> &stats = translations[text[i]];
        dp[i].first = dp[i - 1].first * stats.first;
        dp[i].second = dp[i - 1].first * stats.second + dp[i - 1].second * (stats.first + stats.second);
    }

    pair<long long, long long> &answer = dp[text_len - 1];
    if (answer.first == 1 && answer.second == 0) {
        for (string word : text)
            cout << dict[word] << ' ';
        cout << "\ncorrect\n";
    } 
    else if (answer.first == 0 && answer.second == 1) {
        for (string word : text)
            cout << dict[word] << ' ';
        cout << "\nincorrect\n";
    }
    else {
        cout << answer.first << " correct\n";
        cout << answer.second << " incorrect\n";
    }
    return 0;
}