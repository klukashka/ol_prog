#include <bits/stdc++.h>

using namespace std;
using graph = vector<vector<int>>;

struct skill{
    string name;
    int level;
};

bool kunh(int u, graph& g, vector<int>& mt, vector<bool>& visited){
    if (visited[u]){
        return false;
    }
    visited[u] = true;
    for (int i : g[u]){
        if (mt[i] == -1){
            mt[i] = u;
            return true;
        }
        if (kunh(mt[i], g, mt, visited)){
            mt[i] = u;
            return true;
        }
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<string> people(n);
    vector<unordered_map<string, int>> skills(n);
    for (int i = 0; i < n; i++){
        string name;
        int k;
        cin >> name >> k;
        people[i] = name;
        for (int j = 0; j < k; j++){
            string s;
            int qual;
            cin >> s >> qual;
            skills[i].insert({s, qual});
        }
    }
    graph g(n);

    int m;
    cin >> m;
    vector<skill> vacancies(m);
    for (int i = 0; i < m; i++){
        string p;
        int v;
        cin >> p >> v;
        vacancies[i] = {p, v};
        for (int j = 0; j < n; j++){
            if (skills[j][p] >= v){
                g[j].push_back(i);
            }
        }
    }
    vector<bool> visited(n, false);
    vector<int> mt(m, -1);
    for (int i = 0; i < n; i++){
        visited.assign(n, false);
        kunh(i, g, mt, visited);
    }
    for (int i = 0; i < m; i++){
        if (mt[i] == -1){
            cout << "NO\n";
            return; 
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++){
        cout << vacancies[i].name << ' ' << vacancies[i].level << ' ' << people[mt[i]] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}