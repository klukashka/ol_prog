#include <bits/stdc++.h>

using namespace std;

struct trie{
    struct node{
        map<char, int> go;
        int dp = -1;
        int ind = 0;
    };

    vector<node> data;
    int create_node(){
        data.push_back(node());
        return data.size()-1;
    }

    trie(){create_node();}

    bool can_go(int u, char c){
        return data[u].go.count(c);
    }

    int go(int u, char c){
        return data[u].go[c];
    }

    void insert(const string& s, int k, int index){
        int u = 0;
        for (char c : s){
            if (!can_go(u, c)){
                data[u].go[c] = create_node();
            }
            if (data[u].dp <= k){
                data[u].ind = index;
                data[u].dp = k;
            }
            u = go(u, c);
        }
    }

    int find_max(const vector<char>& s){
        int u = 0;
        for (int i = 0; i < s.size(); i++){
            if (!can_go(u, s[i])){
                return -1;
            }
            u = go(u, s[i]);
        }
        return data[u].ind;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    trie tr;
    string s;
    int k;
    int mx = -1e9, mx_ind;
    vector<int> words_k(n);
    for (int i = 0; i < n; i++){
        cin >> s >> k;
        words_k[i] = k;
        tr.insert(s, k, i);
        if (mx < k){
            mx = k;
            mx_ind = i;
        }
    }
    vector<char> v;
    for (int i = 0; i < q; i++){
        char del, c;
        cin >> del;
        if (del == '+'){
            cin >> c;
            v.push_back(c);
            if (v.size() == 0){
                cout << mx_ind + 1;
            } else {
                cout << tr.find_max(v) + 1 << '\n';
            }
        } else {
            v.pop_back();
            cout << tr.find_max(v) + 1 << '\n';
        }

    }
}