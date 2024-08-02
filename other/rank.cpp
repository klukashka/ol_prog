#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct team{
    string name;
    int points, penalty;
};

bool compare(team team1, team team2){
    if (team1.points != team2.points){
        return team1.points > team2.points;
    } else if (team1.penalty != team2.penalty){
        return team1.penalty < team2.penalty;
    } else {
        return team1.name < team2.name;
    }
};


int main(){
    int n;
    cin >> n;
    vector<team> teams(n);
    for (int i = 0; i < n; i++){
        cin >> teams[i].name >> teams[i].points >> teams[i].penalty;
    }
    sort(teams.begin(), teams.end(), compare);
    for (int i = 0; i < n; i++){
        cout << teams[i].name << endl;
    }
}