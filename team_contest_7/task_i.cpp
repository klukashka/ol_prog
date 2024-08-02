#include <iostream>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll m, n, n_sm=0, m_sm=0;
    cin >> m >> n;
    ll a;
    // s(s+1)/(2*s)
    for (int i = 0; i < m; i++){
        cin >> a;
        m_sm += a;
    }
    m_sm += m;
    for (int i = 0; i < n; i++){
        cin >> a;
        n_sm += a;
    }
    n_sm += n;
    if (m_sm > n_sm){
        cout << "ALICE\n";
    } else if (m_sm == n_sm){
        cout << "TIED\n";
    } else {
        cout << "BOB\n";
    }
}