#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 1){
        int a;
        cin >> a;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
    } else if (n == 2){
        int a, b;
        cin >> a >> b;
        if (a > b){
            cout << 1 << " " << 2 << endl;
            cout << 1 << " " << 1 << endl;
            cout << 2 << " " << 1 << endl;
        } else {
            cout << 1 << " " << 1 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 1 << " " << 2 << endl;
        }
    } else {
        vector<int> local_mins;
        vector<int> local_maxs;
        int min_value = 1000000000;
        int max_value = -1000000000;
        int min_ind = 0;
        int max_ind = 0;

        int a, b, c;
        cin >> a >> b;

        if (a > b){
            local_maxs.push_back(0);
            max_value = a;
            max_ind = 0;
        } else {
            local_mins.push_back(0);
            min_value = a;
            min_ind = 0;
        }
        for (int i = 1; i < n - 1; i++){
            cin >> c;
            if (a < b && b > c){
                local_maxs.push_back(i);
                if (b > max_value){
                    max_value = b;
                    max_ind = i;
                }
                if (b < min_value){
                    min_value = b;
                    min_ind = i;
                }

            }
            if (a > b && b < c){
                local_mins.push_back(i);
                if (b > max_value){
                    max_value = b;
                    max_ind = i;
                }
                if (b < min_value){
                    min_value = b;
                    min_ind = i;
                }

            }
            a = b;
            b = c;
        }
        if (a > b){
            local_mins.push_back(n - 1);
            if (b < min_value){
                min_value = b;
                min_ind = n - 1;
            }
        } else {
            local_maxs.push_back(n - 1);
            if (b > max_value){
                max_value = b;
                max_ind = n - 1;
            }
        }
        cout << local_mins.size() << " ";
        for (int i = 0; i < local_mins.size(); i++){
            cout << local_mins[i] + 1 << " ";
        }
        cout << endl;
        cout << local_maxs.size() << " ";
        for (int i = 0; i < local_maxs.size(); i++){
            cout << local_maxs[i] + 1 << " ";
        }
        cout << endl;
        cout << min_ind + 1 << " " << max_ind + 1;
        cout << endl;
    }
}