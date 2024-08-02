#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double pi = acos(-1);

struct vec2d{
    double x, y;
    vec2d() : x(0), y(0) {}
    vec2d(double _x, double _y) : x(_x), y(_y) {}
    vec2d(const vec2d& _v) : x(_v.x), y(_v.y) {}
};

vec2d operator+(vec2d a, vec2d b){return vec2d(a.x + b.x, a.y + b.y);}
vec2d operator-(vec2d a, vec2d b){return vec2d(a.x - b.x, a.y - b.y);}
vec2d operator*(double x, vec2d b){return vec2d(x * b.x, x * b.y);}

double dot(vec2d a, vec2d b){
    return a.x * b.x + a.y * b.y;
}

double cross(vec2d a, vec2d b){
    return a.x * b.y - a.y * b.x;
}

double vec_angle(vec2d a, vec2d b){
    return abs(atan2(cross(a, b), dot(a, b)));
}

double len(vec2d a){
    return sqrt(dot(a, a));
}

double dist_to_line(vec2d p, vec2d q, vec2d a){
    return abs(cross(q - p, a - p) / len(q - p));
}

double dist_to_segment(vec2d p, vec2d q, vec2d a){
    if (dot(q - p, a - p) < 0 || dot(p - q, a - q) < 0){
        return min(len(a - p), len(a - q));
    } else {
        return dist_to_line(p, q, a);
    }
}

double dist_segment_segment(vec2d p, vec2d q, vec2d R, vec2d S){
    vec2d pq = q - p;
    double l = 0, r = 1;
    for (int i = 0; i < 80; i++){
        double n1 = (2 * l + r) / 3;
        double n2 = (l + 2 * r) / 3;
        double dist_n1 = dist_to_segment(R, S, p + n1 * pq);
        double dist_n2 = dist_to_segment(R, S, p + n2 * pq);
        if (dist_n1 < dist_n2){
            r = n2;
        } else {
            l = n1;
        }
    }
    return dist_to_segment(R, S, p + l * pq);
}

double polar_angle(double x, double y){
    double angle = atan2(y, x);
    if (angle < 0){
        return 2 * pi + angle;
    } else {
        return angle;
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
    int n;
    cin >> n;
    cout.precision(8);
    cout << fixed;
    for (int i = 0; i < n; i++){
        vec2d P, Q, R, S;
        cin >> P >> Q >> R >> S;
        cout << dist_segment_segment(P, Q, R, S) << '\n';
    }
} 