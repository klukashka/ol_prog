#include <bits/stdc++.h>

using namespace std;

using ll = long long;


struct vec2d{
    ll x, y;
    vec2d() : x(0), y(0) {}
    vec2d(ll _x, ll _y) : x(_x), y(_y) {}
    vec2d(const vec2d& _v) : x(_v.x), y(_v.y) {}
};

vec2d operator+(vec2d a, vec2d b){return vec2d(a.x + b.x, a.y + b.y);}
vec2d operator-(vec2d a, vec2d b){return vec2d(a.x - b.x, a.y - b.y);}
vec2d operator*(ll x, vec2d b){return vec2d(x * b.x, x * b.y);}

ll p(vec2d a, vec2d b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll min_p(vector<vec2d> &tr, ll xx){
    ll l = 0, r = xx;
    for (ll i = 0; i < 80; i++){
        vec2d n1 = {l, 0};
        vec2d n2 = {r, 0};
        ll dist_n1 = 0, dist_n2 = 0;
        for (ll j = 0; j < tr.size(); j++){
            dist_n1 += p(tr[j], n1);
            dist_n2 += p(tr[j], n2);
        }
        if (dist_n1 < dist_n2){
            r -= (r - l) / 3;
        } else {
            l += (r - l) / 3;
        }
        // cout << l << " " << r << '\n';
    }
    vec2d n12 = {(l + r) / 2, 0};
    vec2d n1 = {l, 0};
    ll dist_n1 = 0;
    ll dist_12 = 0;
    for (ll j = 0; j < tr.size(); j++){
            dist_12 += p(tr[j], n12);
            dist_n1 += p(tr[j], n1);
        }
    if (dist_12 < dist_n1){
        return (l + r) / 2;
    } else {
        return (r + l) / 2;
    }
}

istream& operator>> (istream & in, vec2d & v){
    ll x, y;
    in >> x >> y;
    v.x = x;
    v.y = y;
    return in;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<vec2d> trees(n);
    for (ll i = 0; i < n; i++){
        cin >> trees[i];
    }
    ll opt_x = min_p(trees, x);
    vec2d opt_x_coord = {opt_x, 0};
    ll sum = 0;
    for (ll j = 0; j < trees.size(); j++){
        sum += p(trees[j], opt_x_coord);
    }
    cout << sum << " " << opt_x << '\n';
}