#include <bits/stdc++.h>

#define all(x) (x.begin(), x.end())

using namespace std;
using ll = long long;

int get_order(char nucleotide) {
    switch (nucleotide) {
        case 'A': return 0;
        case 'T': return 1;
        case 'G': return 2;
        case 'C': return 3;
    }
    return -1;
}

int pairsort(pair<char, int> &p1, pair<char, int> &p2) {
    if (p1.second != p2.second)
        return p1.second > p2.second;
    else
        return get_order(p1.first) < get_order(p2.first);
}

bool is_letter(char c){
    if (c == 'A' || c == 'T' || c == 'G' || c == 'C'){
        return true;
    }
    return false;
}

int main() {
    // Fast input
    cin.tie(0);
    ios::sync_with_stdio(false);

    // The inner vector order is [A, T, G, C]
    vector<vector<int>> dp;
    dp.push_back({0, 0, 0, 0});
    
    // Read the DNA sample and start populating the DP
    int order;
    char buffer = ' ';
    for (int i = 1; is_letter(buffer = getchar()); i++) {
        vector<int> iteration = dp[i - 1];
        order = get_order(buffer);
        iteration[order]++;
        dp.push_back(iteration);
    }

    // Reading the tests
    int test_c;
    if (isdigit(buffer)){
        test_c = buffer;
    } else {
        cin >> test_c;
    }

    int start, end;
    for (int i = 0; i < test_c; i++) {
        cin >> start >> end;
        
        vector<pair<char, int>> answers;
        answers.emplace_back('A', dp[end][0] - dp[start - 1][0]);
        answers.emplace_back('T', dp[end][1] - dp[start - 1][1]);
        answers.emplace_back('G', dp[end][2] - dp[start - 1][2]);
        answers.emplace_back('C', dp[end][3] - dp[start - 1][3]);

        sort(answers.begin(), answers.end(), pairsort);
        for (pair<char, int> &element : answers)
            cout << element.first;
        cout << '\n';
    }
    return 0;
}
