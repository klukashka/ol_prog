#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
    
int main(){
    vector<int> answer;
    string s;
    int n;
    int numbers;
    string best;
    cin >> n;
    cin >> best;
    cin >> numbers;
    for (int j = 0; j < numbers; j++){
        cin >> n;
        cin >> s;
        int cur_char = 0;
        bool flag = false;
        for (int i = 0; i < best.size(); i++){
            if (best[i] == s[cur_char]){
                cur_char++;
            }
            if (cur_char == n){
                flag = true;
                break;
            }
        }
        if (flag){
            answer.push_back(0);
        } else {
            answer.push_back(1);
        }
    }
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i];
    }
}