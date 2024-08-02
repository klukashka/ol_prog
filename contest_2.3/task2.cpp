    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define all(x) x.begin(), x.end()
     
    struct dsu{
        int n;
        vector<int> leader;
        vector<int> rank;
        dsu(int _n) : n(_n), leader(n), rank(n, 1){
            for (int i = 0; i < n; i++){
                leader[i] = i;
            }}
        int find(int u){
            if (leader[u] == u){
                return u;
            }
            leader[u] = find(leader[u]);
            return leader[u];
        }
        bool join(int u, int v){
            int lu = find(u);
            int lv = find(v);
            if (lv == lu){
                return false;
            }
            if (rank[lu] < rank[lv]){
                swap(lu, lv);
            }
            rank[lu] += rank[lv];
            leader[lv] = lu;
            return true;
        }
    };
     
    struct coord{
        int x, y;
    };
     
    const vector<coord> change = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
     
    bool check(int a, int n){
        return 0 <= a && a < n;
    }
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        int n, m, q;
        int x, y, number;
        cin >> t;
        for (int _ = 0; _ < t; _++){
            cin >> n >> m >> q;
            number = 0;
            dsu d(n * m);
            vector<vector<int>> plat(n, vector<int>(m, 0));
            for (int i = 0; i < q; i++){
                cin >> x >> y;
                x--; y--;
                plat[x][y] = 1;
                vector<int> leads;
                for (coord c : change){
                    if (check(c.x + x, n) && check(c.y + y, m)){
                        if (plat[c.x + x][c.y + y]){
                            leads.push_back((c.y + y) * n + c.x + x);
                        }
                    }
                }
                if (leads.size() == 0){
                    number++;
                } else {
                    number++;
                    for (int elem : leads){
                        if(d.join(elem, y * n + x)){
                            number--;
                        }
                    }
                }
                cout << number << '\n';
            }
        }
    }