#include <bits/stdc++.h>

using namespace std;
const int num_const = 48;
using pii = pair<int, int>;
struct info{
    int how_many, num;
    vector<int> indexes;
};

bool compare(info& a, info& b){
    return a.how_many < b.how_many;
}

bool f(vector<info>& m, int index, vector<pii>& ans){
    //cout << m[index].num << " : " << m[index].how_many << ' ' << index <<  '\n';
    if (m[index].num < 10){
        for (int ind : m[index].indexes){
            //cout << m[index].num << " : " << m[index].how_many << " : " << ind <<  '\n';
            bool flag = true;
            for (int i = 0 ; i < ans.size(); i++){
                if ((ans[i].first == ind) || (ans[i].first == ind-1 && ans[i].second == 2)){
                    flag = false;
                    break;
                }
            }
            if (flag){
                ans.push_back({ind, 1});
                if (index < m.size() - 1){
                    if (f(m, index+1, ans)){
                        return true;
                    }
                } else {
                    return true;
                }
                ans.pop_back();
            }
        }
    } else {
        for (int ind : m[index].indexes){
            //cout << m[index].num << " : " << m[index].how_many << " : " << ind <<  '\n';
            bool flag = true;
            for (int i = 0 ; i < ans.size(); i++){
                if (((ans[i].first == ind || ans[i].first == ind+1) && ans[i].second == 1) || 
                ((ans[i].first == ind || ans[i].first == ind+1 || ans[i].first == ind-1) && ans[i].second == 2)){
                    //cout << m[index].num << " asdfa\n";
                    flag = false;
                    break;
                }
            }
            if (flag){
                ans.push_back({ind, 2});
                if (index < m.size() - 1){
                    if (f(m, index+1, ans)){
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return true;
                }
                ans.pop_back();
            }
        }
    }
    return false;
}

int main() {
    string input_data;
    ifstream in_file;
    in_file.open("joke.in");
    in_file >> input_data;

    ofstream out_file;
    out_file.open("joke.out");
    int n;
    if (input_data.length() < 10)
        n = input_data.length();
    else
        n = 9 + (input_data.length() - 9) / 2;

    vector<info> m(n, {0, -1, {}});
    for (int i = 1; i <= n; i++){
        m[i-1].num = i;
        if (i < 10) {
            for (int j = 0; j < input_data.length(); j++) {
                if (input_data[j] == (i + num_const)){
                    m[i-1].how_many++;
                    m[i-1].indexes.push_back(j);
                }
            }
        } else {
            for (int j = 0; j < input_data.length() - 1; j++) {
                if (input_data[j] == (i / 10 + num_const) && input_data[j + 1] == (i % 10 + num_const)){
                    m[i-1].how_many++;
                    m[i-1].indexes.push_back(j);
                }
            }
        }
    }
    sort(m.begin(), m.end(), compare);
    for (int i = 0; i < m.size(); i++){
        cout << m[i].num << ' ' << m[i].how_many << ' ' << m[i].indexes[0] << '\n';
    }
    // cout << '\n';
    // for (int i = 0; i < m.size(); i++){
    //     for (int j = 0; j < m[i].indexes.size(); j++){
    //         cout << m[i].indexes[j] << ' ';
    //     }
    //     //cout << '\n';
    // }
    //cout << '\n';
    vector<pii> ans;
    f(m, 0, ans);
    
    sort(ans.begin(), ans.end());
    // for (int i : ans){
    //     cout << i << ' ';
    // }
    for (pii p : ans){
        cout << p.first << ' ' << p.second << '\n';
    }
    for (pii p : ans){
        if (p.second == 1){
            out_file << input_data[p.first] << ' ';
        } else {
            out_file << input_data[p.first] << input_data[p.first + 1] << ' ';
        }
    }
}