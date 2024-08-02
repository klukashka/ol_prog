#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    unsigned long long int ans = 0;
    cin >> n;
    priority_queue<long long int> q;
    for (long long int i = 0; i < n; i++){
        long long int num;
        cin >> num;
        q.push(num);
    }
    long long int prev;
    long long int segment;
    prev = q.top();
    q.pop();
    for (long long int i = 1; i <= n; i++){
        segment = prev - q.top();
        prev = q.top();
        q.pop();
        ans += (n - i) * i * segment;
    }
    cout << ans << '\n';
}
