#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int f(int a, int b){
    while (a != b){
        if (a > b){
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int g(int a, int b){
    while (a && b){
        if (a > b){
            a = a % b;
        }
        swap(a, b);
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    auto beg1 = clock();
    int ff = f(n ,m);
    auto end1 = clock();
    cout << ff << " " << end1 - beg1 << '\n';

    auto beg2 = clock();
    int gg = g(n ,m);
    auto end2 = clock();
    cout << gg << " " << end2 - beg2 << '\n';
}