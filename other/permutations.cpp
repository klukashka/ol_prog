#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> x(n, 0);
    vector<int> counter(n, 0);
    unordered_set<int> elements;
    bool flag = true;
    
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        x[i] = num;
        if (num > 0 && num <= n){
            counter[num - 1]++;
            elements.insert(num);
            if (counter[num - 1] > 1){
                flag = false;
                break;
            }
        } else if (num > n){
            flag = false;
            break;
        }
    }
    if (flag){
        stack<int> v;
        for (int i = 1; i <= n; i++){
            if (elements.find(i) == elements.end()){
                v.push(i);
            }
        }
        for (int i = 0; i < n; i++){
            if (x[i] == 0){
                cout << v.top() << " ";
                v.pop();
            } else {
                cout << x[i] << " ";
            }
        }
    } else {
        cout << -1;
    }
}