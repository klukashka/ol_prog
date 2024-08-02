#include <bits/stdc++.h>

using namespace std;

struct info{
    int turn, step;
};

void count(const vector<int>& a, int n, vector<info>& res_vector){
    int res = 0;
    int turn = 1;
    for (int i = 0; i < n; i++){
        if(a[i] == 0){
            res += turn;
        } else if (a[i] == -1){
            turn = -1;
        } else {
            turn = 1;
        }
        res_vector[i] = {turn, res};
    }
}

void count2(const vector<int>& a, int n, vector<info>& res_vector){
    int res = 0;
    int turn = 1;
    for (int i = 0; i < n; i++){
        if(a[i] == 0){
            res += turn;
        } else if (a[i] == -1){
            turn = -1;
        } else {
            turn = 1;
        }
        res_vector[i] = {turn, res};
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> commands(n);
    for (int i = 0; i < n; i++){
        if (s[i] == 'L'){
            commands[i] = -1;
        } else if (s[i] == 'R'){
            commands[i] = 1;
        } else {
            commands[i] = 0;
        }
    }
    vector<info> pre_res(n), pre_res2(n);

    count(commands, n, pre_res);
    count2(commands, n, pre_res2);
    unordered_set<int> poss;
    int res1, res2;
    if (commands[0] == 0){
        res1 = pre_res[n-1].step - 1;
        res2 = -pre_res[n-1].step + 1;
    } else if (commands[0] == 1){
        res1 = pre_res[n-1].step + 1;
        res2 = -pre_res[n-1].step;
    } else {
        res1 = -pre_res[n-1].step - 1;
        res2 = -pre_res[n-1].step;
    }
    cout << res1 << ' ' << res2 << '\n';
    poss.insert(res1);
    poss.insert(res2);
    for (int i = 1; i < n; i++){
        if (commands[i] == 0){
            res1 = pre_res[i-1].step + 
                (pre_res[n-1].step - pre_res[i-1].step - 1*pre_res[i-1].turn);
            res2 = pre_res[i-1].step - 
                (pre_res[n-1].step - pre_res[i-1].step - 1*pre_res[i-1].turn);
        } else if (commands[i] == 1){
            res1 = res2 = pre_res[i-1].step + pre_res[i-1].turn* 
                (pre_res[n-1].step - pre_res[i-1].step + 1);
            res2 = pre_res[i-1].step - 
                (pre_res[n-1].step - pre_res[i-1].step);
        } else {
            res1 = res2 = pre_res[i-1].step + pre_res[i-1].turn* 
                (pre_res[n-1].step - pre_res[i-1].step + 1);
            res2 = pre_res[i-1].step - 
                (pre_res[n-1].step - pre_res[i-1].step);
        }
        cout << res1 << ' ' << res2 << '\n';
        poss.insert(res1);
        poss.insert(res2);
    }
    cout << poss.size() << '\n';
    // if (commands[n-1] == 0){
    //     pre_res[n-1] = {1, 1};
    // }
    // if (commands[n-1] == 1){
    //     pre_res[n-1] = {1, 0};
    // }
    // if (commands[n-1] == -1){
    //     pre_res[n-1] = {-1, 0};
    // }
    // for (int i = n-2; i >= 0; i++){
    //     if (commands[i] == 0){
    //         pre_res[i] = {pre_res[i+1].turn, pre_res[i+1].step + 1};
    //     }
    //     if (commands[i] == 1){
    //         pre_res[i] = {pre_res[i+1].turn, pre_res[i+1].step + 1};
    //     }
    // }
}