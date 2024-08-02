#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()
using ll = long long;

struct trie{
    struct node{
        vector<int> go = {-1, -1};
        int end = 0, dp = 0;
    };
    vector<node> data;
    int create_node(){
        data.push_back(node());
        return data.size()-1;
    }

    trie(){create_node();}

    bool can_go(int u, bool c){
        return data[u].go[c] >= 0;
    }

    int go(int u, bool c){
        return data[u].go[c];
    }

    int find_min(const vector<bool>& s, const vector<int>& pows){
        int ans = 0;
        int u = 0;
        for (int c = 0; c < 31; c++){
            if (s[c] == 0){
                if (can_go(u, 0) && data[go(u, 0)].dp > 0){
                    // mult by 0;
                    u = go(u, 0);
                } else if (can_go(u, 1) && data[go(u, 1)].dp > 0){
                    ans += pows[c];
                    u = go(u, 1);
                }
            } else {
                if (can_go(u, 1) && data[go(u, 1)].dp > 0){
                    // mult by 0;
                    u = go(u, 1);
                } else if (can_go(u, 0) && data[go(u, 0)].dp > 0){
                    ans += pows[c];
                    u = go(u, 0);
                }
            }
        }
        
        return ans;
    }

    int find_max(const vector<bool>& s, const vector<int>& pows){
        int ans = 0;
        int u = 0;
        for (int c = 0; c < 31; c++){
            if (s[c] == 0){
                if (can_go(u, 1) && data[go(u, 1)].dp > 0){
                    ans += pows[c];
                    u = go(u, '1');
                } else if (can_go(u, 0) && data[go(u, 0)].dp > 0){
                    // mult by 0;
                    u = go(u, 0);
                }
            } else{
                if (can_go(u, 0) && data[go(u, 0)].dp > 0){
                    ans += pows[c];
                    u = go(u, 0);
                } else if (can_go(u, 1) && data[go(u, 1)].dp > 0){
                    // mult by 0;
                    u = go(u, 1);
                }
            }
        }
        
        return ans;
    }

    void insert(const vector<bool>& s){
        int u = 0;
        for (bool c : s){
            if (!can_go(u, c)){
                data[u].go[c] = create_node();
            }
            data[u].dp++;
            u = go(u, c);
        }
        data[u].dp++;
        data[u].end++;
    }

    void erase(const vector<bool>& s){
        int u = 0;
        for (bool c : s){
            assert(can_go(u, c));
            data[u].dp--;
            u = go(u, c);
        }
        data[u].dp--;
        data[u].end--;
    }
};

vector<bool> dec_to_bin(int s){
    vector<bool> ans(31);
    for (int i = 0; i < 31; i++){
        ans[i] = s % 2;
        s /= 2;
    }
    reverse(all(ans));
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pows(31);
    pows[0] = 1;
    for (int i = 1; i < 31; i++){
        pows[i] = pows[i-1] * 2;
    }

    reverse(all(pows));
    // ifstream file;
    // file.open("task_f.in");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<bool>> a2(n); // already reversed
    for (int i = 0; i < n; i++){
        a2[i] = dec_to_bin(a[i]);
    }

    trie tr;
    for (vector<bool> v : a2){
        tr.insert(v);
    }
    // ofstream file_out;
    // file_out.open("task_f.out");
    // for (string s : a2){
    //     cout << s << '\n';
    // }
    for (int i = 0; i < n; i++){
        tr.erase(a2[i]);

        int min_xor, max_xor;
        min_xor = tr.find_min(a2[i], pows);
        max_xor = tr.find_max(a2[i], pows);
        // for (int v : min_xor){
        //     cout << v;
        // } cout << " mn for " << a2[i] << '\n';
        // for (int v : max_xor){
        //     cout << v;
        // } cout << " mx for " << a2[i] << '\n';

        cout << min_xor << ' ' << max_xor << '\n';
        tr.insert(a2[i]);
    }
}