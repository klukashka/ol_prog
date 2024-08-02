#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct num_power{
    int prime, power;
};

vector<num_power> powering(long long int a){
    vector<num_power> ans;
    for (int i = 2; i * 2 <= a; i++){
        bool prime = true;
        for (int j = 2; j*j <= i; j++){
            if ((i % j) == 0){
                prime = false;
                break;
            } 
        }
        if (prime){
            if (a % i == 0){
                int b = a;
                int power = 0;
                while (b % i == 0){
                    power += 1;
                    b = b / i;
                }
                num_power two;
                two.prime = i;
                two.power = power;
                ans.push_back(two);
            }
        }
    }
    if (ans.size() == 0){
        num_power two;
        two.prime = a;
        two.power = 1;
        ans.push_back(two);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<num_power> answer;
    long long int n, res = 1;
    cin >> n;
    for (int i = 0; i < n ; i++){
        long long int num;
        cin >> num;
        vector<num_power> powers = powering(num);
        for (int i = 0; i < powers.size(); i++){
            bool flag = false;
            for (int j = 0; j < answer.size(); j++){
                if (answer[j].prime == powers[i].prime){
                    answer[j].power = max(answer[j].power, powers[i].power);
                    flag = true;
                    break;
                }
            }
            if (!flag){
                answer.push_back(powers[i]);
            }
        }
        for (int j = 0; j < answer.size(); j++){
            cout << powers[i].prime << " " << powers[i].power << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < answer.size(); i++){
        res = res * answer[i].prime * answer[i].power;
    }
    cout << res << endl;
}