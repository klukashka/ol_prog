#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

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
            // data[u].dp++;
            u = go(u, c);
        }
        // data[u].dp++;
        // data[u].end++;
    }

    bool find(const string& s){
        int u = 0;
        for (char c : s){
            if (c == '-'){
                return false;
            }
            if (can_go(u, c)){
                u = go(u, c);
                continue;
            }
            break;
        }
        return true;
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
        reverse(all(s));
        tr.insert(s);
    }
    int m;
    cin >> m;
    while (m--){
        string s;
        cin >> s;
        reverse(all(s));
        if (tr.find(s)){
            cout << "Good\n";
        } else {
            cout << "Bad\n";
        }
    }
}