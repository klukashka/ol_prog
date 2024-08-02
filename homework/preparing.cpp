#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long double> A(n);
    vector<long double> P(n);
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        cin >> P[i];
    }
    sort(A.begin(), A.end());
    sort(P.begin(), P.end());
    long double res = 0;
    long double sm = 0;
    for (int i = 0; i < n; i++){
        sm += P[i];
    }
    for (int i = 0; i < n; i++){
        res += P[i] * A[i];
    }
    cout << res  / sm << '\n';
}