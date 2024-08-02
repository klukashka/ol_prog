#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

struct info{
    ll money;
    short ind;
};
// info is about how much i DO have and from where i DID come
vector<info> path(short &n, short &k, vector<int> &prices){
    vector<info> ways(n + 1);
    for (short i = 1; i <= k; i++){
        ways[i].money = prices[i];
        ways[i].ind = 0;
    }
    for (short i = k + 1; i <= n; i++){
        ways[i].money = ways[i - k].money;
        ways[i].ind = i - k;
        for (short j = i - k + 1; j < i; j++){
            if (ways[j].money < ways[i].money){
                ways[i].money = ways[j].money;
                ways[i].ind = j;
            }
        }
        ways[i].money += prices[i];
    }
    return ways;
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    short n, k;
    cin >> n >> k;
    vector<int> prices(n + 1);
    for (short i = 1; i < n; i++){
        cin >> prices[i];
    }
    if (n > k){
        prices[n] = 0;
        vector<info> solution = path(n, k, prices);
        cout << solution[n].money << '\n';
        vector<short> ans;
        short now = n;
        while (now != 0){
            ans.push_back(now);
            now = solution[now].ind;
        }
        cout << ans.size() + 1 << '\n';
        cout << 0 << " ";
        for (short i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
        cout << '\n';
    } else {
        cout << 0 << '\n' << 2 << '\n' << 0 << " " << n << '\n';
    }
}