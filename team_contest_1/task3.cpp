#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

long long mx(long long a, long long b){
    if (a >= b){
        return a;
    } else {
        return b;
    }
}

void f(vector<long long int>& m, long long int d){
    sort(m.begin(), m.end());
    ll diff21 = m[2] - m[1];
    ll diff10 = m[1] - m[0];
    if (diff10 < d){
        m[0] += diff10;
        d -= diff10;
    } else {
        m[0] += d;
        return ;
    }
    if (2 * diff21 < d){
        m[0] += diff21;
        m[1] += diff21;
        d -= 2 * diff21;
        if (d % 3 == 0){
            m[0] += d / 3;
            m[1] += d / 3;
            m[2] += d / 3;
        } else if (d % 3 == 1){
            m[0] += d / 3;
            m[0]++;
            m[1] += d / 3;
            m[2] += d / 3;
        } else {
            m[0] += d / 3;
            m[0]++;
            m[1] += d / 3;
            m[1]++;
            m[2] += d / 3;
        }
    } else {
        if (d % 2 == 0){
            m[0] += d / 2;
            m[1] += d / 2;
        } else {
            m[0] += d / 2;
            m[1] += d / 2;
            m[0]++;
        }
    }
    //sort(m.begin(), m.end());
    //cout << m[0] << " " << m[1] << " " << m[2] << '\n';
}

long long int res (long long int a, long long int b, long long int c){
    return a * a + b * b + c * c + 7 * min(a, min(b, c));
}

int main(){
    int n;
    cin >> n;
    for (long long int i = 0; i < n; i++){
        long long int a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<long long int> m(3);
        m[0] = a;
        m[1] = b;
        m[2] = c;
        f(m, d);
        sort(m.begin(), m.end());
        long long int res1 = mx(res(a, b, c + d), mx(
            res(a, b + d, c), res(a + d, b, c)));
        //cout << res1 << "res1" << '\n';
        long long int res2 = res(m[0], m[1], m[2]);
        //cout << res2 << "res2" << '\n';
        if (res1 < res2){
            cout << res2 << '\n';
        } else {
            cout << res1 << '\n';
        }
    }
}