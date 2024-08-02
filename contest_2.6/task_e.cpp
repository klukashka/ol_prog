#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()

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

    vector<int> d;
    int t = 0;
    void dfs(int u, int& t, vector<node>& data){
        d[u] = t++;
        for (auto const& [key, value] : data[u].go){
            // cout << u << ' ' << key << " data\n";
            dfs(value, t, data);
        }
        t--;
    }

    void dfs_search(int u, int& res, vector<char>& res_path, vector<char>& path, const vector<node>& data){
        if (d[u] * data[u].dp > res){
            res_path = path;
            res = d[u] * data[u].dp;
        }
        for (auto const& [key, value] : data[u].go){
            path.push_back(key);
            dfs_search(value, res, res_path, path, data);
        }
        path.pop_back();
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

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    trie tr;
    string s;
    cin >> s;
    int s_size = s.size();
    for (int i = 0; i <= s.size(); i++){
        string p = s.substr(i, s_size-i);
        tr.insert(p);
    }
    tr.d.resize(tr.data.size());
    tr.dfs(0, tr.t, tr.data);
    int res = 0;
    vector<char> path;
    vector<char> res_path;
    tr.dfs_search(0, res, res_path, path, tr.data);
    // for (int i = 0; i < tr.data.size(); i++){
    //     cout << i << " :  ";
    //     for (auto const& [key, value] : tr.data[i].go){
    //         cout << key << ' ' << value << " ;  ";
    //     }
    //     cout << '\n';
    // }
    for (char v : res_path){
        cout << v;
    }
    cout << '\n';
}