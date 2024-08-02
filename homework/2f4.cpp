#include <bits/stdc++.h>

using namespace std;

struct trie{
    struct node{
        map<char, int> go;
        int end = 0, dp = 0;
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

    void insert(const string& s){
        int u = 0;
        for (char c : s){
            if (!can_go(u, c)){
                data[u].go[c] = create_node();
            }
            data[u].dp++;
            u = go(u, c);
        }
        data[u].dp++;
        data[u].end++;
    }

    void erase(const string& s){
        int u = 0;
        for (char c : s){
            assert(can_go(u, c));
            data[u].dp--;
            u = go(u, c);
        }
        data[u].dp--;
        data[u].end--;
    }

    string lex_min(int k){
        int u = 0;
        string s;
        while (k > data[u].end){
            k -= data[u].end;
            for (auto [c, v] : data[u].go){
                if (data[v].dp < k){
                    k -= data[v].dp;
                } else {
                    s.push_back(c);
                    u = go(u, c);
                    break;
                }
            }
        }
        return s;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    trie tr;
    while (n--){
        string s;
        cin >> s;
        if ('0' <= s[0] && s[0] <= '9'){
            int k = stoi(s);
            string t = tr.lex_min(k);
            cout << t << '\n';
            tr.erase(t);
        } else {
            tr.insert(s);
        }
    }
}