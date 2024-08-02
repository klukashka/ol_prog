#include <bits/stdc++.h>
    
using namespace std;
    
using ll = long long;
    
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int students_c;
    cin >> students_c;
    
    vector<ll> students(students_c);
    multiset<ll, greater<ll>> pairs;
    
    for (int i = 0; i < students_c; i++)
        cin >> students[i];
    
    sort(students.begin(), students.end());
    
    // Assume at first that the most optimal way is to make
    // the first student the host
    for (int i = 1; i <= students_c / 2; i++)
        pairs.insert(students[students_c - i] + students[i]);
    
    const int center = students_c / 2;
    ll min_delta = *(pairs.begin()) - *(--pairs.end());
    
    for (int i = 1; i < students_c; i++) {
        for (auto i = pairs.begin(); i != pairs.end(); i++){
        cout << *i << ' ';
    }
    cout<< '\n';
        if (i > center) {
            pairs.erase(students[2 * center - i] + students[i]);
            pairs.insert(students[2 * center - i] + students[i - 1]);
        } else {
            pairs.erase(students[i] + students[students_c - i]);
            pairs.emplace(students[i - 1] + students[students_c - i]);
        }
    
        min_delta = min(min_delta, *(pairs.begin()) - *(--pairs.end()));
    }
    
    cout << min_delta << endl;
}