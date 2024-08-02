#include <bits/stdc++.h>

using namespace std; 
using graph = vector<vector<int>>;
int inf = 2e9;

struct item{
    int ind, w;
};

int compare_strings(string& s1, string& s2){
    int counter = 0;
    for (int i = 0; i < s1.size(); i++){
        if (s1[i] == s2[i]){
            continue;
        }
        counter++;
        if (counter > 1){
            break;
        }
    }
    return counter;
}

void bfs(int start, vector<vector<int>>& ways, graph& dp){
    vector<bool> been_there(ways.size(), false);
    queue<item> q;
    dp[start][start] = 0;
    been_there[start] = true;
    q.push({start, 0});
    while (!q.empty()){
        item u = q.front();
        q.pop();
        for (int v : ways[u.ind]){
            if (been_there[v]){
                continue;
            }
            been_there[v] = true;
            dp[start][v] = u.w + 1;
            q.push({v, dp[u.ind][v]});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> words(n);
    unordered_map<string, int> word_to_ind;
    graph dp(n, vector<int>(n, inf));
    vector<vector<int>> ways(n);
    for (int i = 0; i < n; i++){
        cin >> words[i];
        word_to_ind[words[i]] = i;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j){
                continue;
            }
            int val = compare_strings(words[i], words[j]);
            if (val > 1){
                continue;
            } else {
                ways[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++){
        bfs(i, ways, dp);
    }
    string s_cur, s_prev;
    cin >> s_cur;
    s_prev = s_cur;
    int sm = k;
    cout << s_prev << '\n';
    for (int i = 1; i < m; i++){
        cin >> s_cur;
        // if (dp[word_to_ind[s_prev]][word_to_ind[s_cur]] == inf){
        //     sm += k;
        // } else {
            sm += min(dp[word_to_ind[s_prev]][word_to_ind[s_cur]], k);
        // }
        // sm += min(dp[word_to_ind[s_prev]][word_to_ind[s_cur]], k);
        cout << s_cur << "   " << dp[word_to_ind[s_prev]][word_to_ind[s_cur]] << "     " << sm << '\n';
        s_prev = s_cur;
    }
    cout << sm << '\n';
}