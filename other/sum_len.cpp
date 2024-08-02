#include <iostream>
#include <vector>

using namespace std;

struct ab{
    int a, b;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long int sm = 0;
    cin >> n;
    vector<int> dots(n);
    for (int i = 0; i < n; i++){
        cin >> dots[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            sm += abs(dots[i] - dots[j]);
        }
        for (int j = i + 1; j < n; j++){
            sm += abs(dots[i] - dots[j]);
        }
    }
    cout << sm / 2 << endl;
}