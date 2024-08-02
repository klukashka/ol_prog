#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int inf = 1e9;

struct item{
    int from, to, num;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    vector<vector<item>> edges(2000);
    for (int i = 0; i < k; i++){
        int num1, num2;
        cin >> num1 >> num2;
        num1--;
        num2--;
        edges[num1].push_back({num1, num2, i+1});
    }
    int t;
    vector<int> s(2);
    cin >> t >> s[0] >> s[1];
    t--;
    s[0]--;
    s[1]--;
    vector<int> final_ans;
    for (int start : s){
        vector<bool> been_there(2000, false);
        vector<int> dp(2000, inf);
        dp[start] = 0;
        vector<int> prev_v(2000, -1);
        vector<int> prev_edge(2000, -1);
        prev_v[start] = start;
        prev_edge[start] = start;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({dp[start], start});
        while (q.size()){
            pii cur = q.top();
            q.pop();
            int u = cur.second;
            if (been_there[u]){
                continue;
            }
            been_there[u] = true;
            for (item v : edges[u]){
                if (dp[u] + 1 < dp[v.to]){
                    dp[v.to] = dp[u] + 1;
                    q.push({dp[v.to], v.to});
                    prev_v[v.to] = u;
                    prev_edge[v.to] = v.num;
                }
            }
        }
        if (prev_v[t] != -1){
            vector<int> ans = {prev_edge[t]};
            int it = prev_v[t];
            while (prev_v[it] != it){
                ans.push_back(prev_edge[it]);
                it = prev_v[it];
            }
            if (start == s[0]){
                final_ans = ans;
            } else if (final_ans.size() > ans.size() || final_ans.size() == 0){
                final_ans = ans;
            }
            // for (int i = ans.size() - 1; i > -1; i--){
            //     cout << ans[i] << '\n';
            // }
            // cout << "ans\n";
            // for (int i = final_ans.size() - 1; i > -1; i--){
            //     cout << final_ans[i] << '\n';
            // }
            // cout << "fin\n";
        }
    }
    if (final_ans.size() != 0){
        cout << final_ans.size() << '\n';
        for (int i = final_ans.size() - 1; i > -1; i--){
            cout << final_ans[i] << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
}