#include <bits/stdc++.h>
using namespace std;

int f(int t, int a, int b){
    return t / a + t / b + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, res;
    cin >> n >> a >> b;
    int t0 = min(a, b);
    int low = 1, high = 100000000, mid, val;
    while (low <= high){
        mid = low + (high - low) / 2;
        val = f(mid, a, b);
        if (n == val){
            res = mid;
            break;
        } else if (n < val){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << t0 << '\n';
    cout << low <<" "<< mid <<" "<<high<<'\n';
}