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

vec2d sim_coord(vec2d aa, vec2d bb, vec2d s){
    double sin_a = cross(bb - aa, s - aa) / (len(bb - aa) * len(s - aa));
    return 2 * sin_a * (aa - s) + (s - aa);
}
    
double dist_to_segment(vec2d p, vec2d q, vec2d a){
    if (dot(q - p, a - q) > 0 || dot(p - q, a - p) > 0){
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

vec2d optimal_coord(vec2d p, vec2d q, vec2d s, vec2d base){
    vec2d pq = q - p;
    double l = 0, r = 1;
    for (int i = 0; i < 70; i++){
        double n1 = (2 * l + r) / 3;
        double n2 = (l + 2 * r) / 3;
        double sum_n1 = len((n1 * pq) - s + p) + len((n1 * pq) - base + p);
        double sum_n2 = len((n2 * pq) - s + p) + len((n2 * pq) - base + p);
        if (sum_n1 < sum_n2){
            r = n2;
        } else {
            l = n1;
        }
        //cout << (p + l * pq).x << " " << (p + l * pq).y << " " << i << '\n';
    }
    //cout << (p + l * pq).x << " " << (p + l * pq).y << " " << "preanswer" << '\n';
    return p + l * pq;
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
    cout.precision(8);
    cout << fixed;
    vec2d base, a, b, c;
    cin >> base;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    vector<vec2d> dots(m);
    for (int i = 0; i < m; i++){
        cin >> dots[i];
    }
    for (int i = 0; i < m; i++){
        double mn;
        vec2d ans;
        vec2d ab_ans = optimal_coord(a, b, dots[i], base);
        vec2d ac_ans = optimal_coord(a, c, dots[i], base);
        vec2d bc_ans = optimal_coord(b, c, dots[i], base);

        mn = len(ab_ans - dots[i]) + len(ab_ans - base);
        ans = ab_ans;
        if (len(ac_ans - dots[i]) + len(ac_ans - base) < mn){
            mn = len(ac_ans - dots[i]) + len(ac_ans - base);
            ans = ac_ans;
        }
        if (len(bc_ans - dots[i]) + len(bc_ans - base) < mn){
            mn = len(bc_ans - dots[i]) + len(bc_ans - base);
            ans = bc_ans;
        }
        cout << ans.x << " " << ans.y << '\n';
    }
} 