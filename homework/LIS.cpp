#include <iostream>
#include <vector>

using namespace std;

vector<short> LIS(vector<int> &a){
    vector<vector<short>> lis(a.size());
    lis[0] = {0};
    for (short i = 1; i < a.size(); i++){
        short ans_j = -1;
        for (short j = 0; j < i; j++){
            if (a[lis[j][lis[j].size() - 1]] < a[i]){
                if (ans_j != -1){
                    if (lis[ans_j].size() < lis[j].size()){
                        ans_j = j;
                    }
                } else {
                    ans_j = j;
                }
            }
        }
        if (ans_j == -1){
            lis[i] = {i};
        } else {
            lis[i] = lis[ans_j];
            lis[i].push_back(i);
            
        }
    }
    short mx_ans = 0;
    for (short i = 0; i < a.size(); i++){
        if (lis[i].size() > lis[mx_ans].size()){
            mx_ans = i;
        }
    }
    return lis[mx_ans];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++){
            cin >> v[j];
        }
        vector<short> ans = LIS(v);
        cout << ans.size() << endl;
        for (short j = 0; j < ans.size(); j++){
            cout << ans[j] + 1 << " ";
        }
        cout << endl;
    }
}