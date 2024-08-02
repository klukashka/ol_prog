#include <iostream>
#include <fstream>
#include <vector>

struct info{
    int from, to;
};

struct question{
    int from, to, time;
};

using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ifstream in_file("knockout.in");
    int n, m;
    in_file >> n >> m;
    vector<info> v(n);
    vector<question> q(m);
    for (int i = 0; i < n; i++){
        in_file >> v[i].from >> v[i].to;
    }
    for (int i = 0; i < m; i++){
        in_file >> q[i].from >> q[i].to >> q[i].time;
    }
    for (question quest : q){
        
    }
}