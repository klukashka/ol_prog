#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Pair{
    string passw;
    bool in;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    map<string, Pair> info;
    while (cin >> s){
        if (s == "register"){
            string login;
            string password;
            cin >> login >> password;
            if (info.find(login) == info.end()){
                struct Pair p = {password, false};
                info[login] = p;
                cout << "account created" << endl;
            } else {
                cout << "login already in use" << endl;
            }
        } else if (s == "login"){
            string login;
            string password;
            cin >> login >> password;
            if (info.find(login) != info.end()){
                if (info[login].passw == password){
                    if (info[login].in){
                        cout << "already logged in" << endl;
                    } else {
                        info[login].in = true;
                        cout << "logged in" << endl;
                    }
                } else {
                    cout << "wrong account info" << endl;
                }
            } else {
                cout << "wrong account info" << endl;
            }
        } else {
            string login;
            cin >> login;
            if (info.find(login) != info.end()){
                if (info[login].in){
                    info[login].in = false;
                    cout << "logged out" << endl;
                } else {
                    cout << "incorrect operation" << endl;
                }
            } else {
                cout << "incorrect operation" << endl;
            }
        }
    }
}