#include <bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> l, r;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        l.insert(num);
        while (l.size() + (i + 1) % 2 > r.size()){
            int x = l.erase();
        }
    }
}