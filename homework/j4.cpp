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
        cout.precision(7);
        cout << fixed;
        for (int i = 0; i < n; i++){
            vec2d a, p, q;
            cin >> a >> p >> q;
            vec2d pa = a - p;
            vec2d pq = q - p;
            double square = cross(pq, pa);
            double ans = square / len(pq);
            cout << abs(ans) << '\n';
        }
    }