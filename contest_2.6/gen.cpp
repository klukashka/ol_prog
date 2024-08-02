#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ofstream file;
    file.open("task_f.in");
    int n = 1e5;
    file << n << '\n';
    for (int i = 0; i < n; i++){
        file << rand() % 1000000000 << '\n';
    }
}