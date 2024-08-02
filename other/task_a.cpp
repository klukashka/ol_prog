#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<long long int, vector<long long int>, greater<long long int>> q;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        q.push(num);
    }
    while (q.size() != 1){
        long long int a = q.top();
        q.pop();
        cout << a << " " << q.top() << endl;;
        a += q.top();
        q.pop();
        q.push(a);
    }
    cout << endl;
}