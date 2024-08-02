#include <bits/stdc++.h>

using namespace std;


struct info{
    string name;
    int score;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, vector<string>, greater<int>> leaders;
    vector<int> best_results(4, 0);
    for (int i = 0; i < n; i++){
        int score = 0;
        string name;
        cin >> name;
        int prog;
        cin >> prog;
        score += prog * 10;
        int mn, mx, val;
        cin >> val;
        score += val;
        mn = val; mx = val;
        for (int j = 0; j < 5; j++){
            cin >> val;
            score += val;
            if (val < mn){
                mn = val;
            }
            if (val > mx){
                mx = val;
            }
        }
        score -= (mx + mn);
        leaders[score].push_back(name);
    }
    int counter = 0;
    for (auto const& [key, val] : leaders){
        if (counter <= 2){
            for (string st : val){
                cout << st << ' ' << key << '\n';
                counter++;
            }
        } else {
            break;
        }
    }
}