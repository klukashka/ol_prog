#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_apps(vector<int> app_1, vector<int> app_2) {
    if ((app_1[2] - app_1[1]) == (app_2[2] - app_1[1])){
        return app_2[2] > app_1[2];
    } else {
        return (app_1[2] - app_1[1]) < (app_2[2] - app_1[1]);
    }   
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int apps_count, free_space;
    cin >> apps_count >> free_space;

    vector<vector<int>> apps;
    for (int i = 0; i < apps_count; i++) {
        vector<int> application(3);
        application[0] = i + 1;
        cin >> application[1] >> application[2];
        apps.push_back(application);
    }

    sort(apps.begin(), apps.end(), cmp_apps);

    vector<int> install_order;
    for (vector<int> &app : apps) {
        if (max(app[1], app[2]) <= free_space) {
            free_space -= app[2];
            install_order.push_back(app[0]);
        }
    }

    cout << install_order.size() << '\n';
    
    for (int app_id : install_order)
        cout << app_id << ' ';
    cout << '\n';
}