/*
 * @file Convex Hull2.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-06-20
 * @copyright Copyright (c) 2024
 * @problem: https://codeforces.com/problemset/problem/166/B
 * @approach: 
 * @explanation:
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3e5 + 9;
const int inf = 1e100;
const int eps = 1e-9;
const int PI = acos(-1.0);

int sign(int x) {
    return (x > eps) - (x < -eps);
}
struct PT {
    int x, y;
    PT() {}
    PT(int x, int y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const {
        return PT(x + a.x, y + a.y);
    }
    PT operator - (const PT &a) const {
        return PT(x - a.x, y - a.y);
    }
    PT operator * (const int a) const {
        return PT(x * a, y * a);
    }
    friend PT operator * (const int &a, const PT &b) {
        return PT(a * b.x, a * b.y);
    }
    PT operator / (const int a) const {
        return PT(x / a, y / a);
    }
    bool operator == (PT a) const {
        return sign(a.x - x) == 0 && sign(a.y - y) == 0;
    }
    bool operator < (PT a) const {
        return sign(a.x - x) == 0 ? y < a.y : x < a.x;
    }
    bool operator > (PT a) const {
        return sign(a.x - x) == 0 ? y > a.y : x > a.x;
    }
    int norm() {
        return sqrt(x * x + y * y);
    }
    int norm2() {
        return x * x + y * y;
    }
    int arg() {
        return atan2(y, x);
    }
    PT truncate(int r) { // returns a point with norm r and having same direction
        int k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};

int dot(PT a, PT b) {
    return a.x * b.x + a.y * b.y;
}
int dist2(PT a, PT b) {
    return dot(a - b, a - b);
}

int dist(PT a, PT b) {
    return sqrt(dot(a - b, a - b));
}

int cross(PT a, PT b) {
    return a.x * b.y - a.y * b.x;
}
/*
    return 
        -1 = clockwise
         0 = colinear 
         1 = counter_clockwise
*/
int orientation(PT a, PT b, PT c) {
    return sign(cross(b - a, c - a));
}

struct polygon {
    vector<PT> p;
    polygon() {}
    polygon(int _n) { p.resize(_n); }
    polygon(vector<PT> _p) { p = _p; }
    void add(PT q) { p.push_back(q); }
    // return the circumference of the polygon.
    int circumference() {
        int ans=0; int n = p.size();
        for (int i = 0; i < n; i++) ans += dist(p[i], p[(i + 1) % n]);
        return ans;
    }
    // return the area of the polygon...
    int area() {
        int ans = 0; int n = p.size();
        for (int i = 0; i < n; i++){
            int res = cross(p[i], p[(i + 1) % n]);
            ans += res;
        }
        return ans > 0 ? ans : -ans;
    }
    // directon of the polygon -1 if clockwise, 1 if counter_clockwise
    bool get_direction() {
        int ans = 0; int n = p.size();
        for (int i = 0; i < n; i++) ans += cross(p[i], p[(i + 1) % n]);
        return (sign(ans) > 0) ? 1 : -1;
    }
    // return the convex hull(counter_clockwise) from that polygon...
    // colinear_points will not considered...
    polygon convex_hull() {
        vector<PT> v = p;
        sort(v.begin(), v.end());
        vector<PT> up, dn;
        for (auto& p : v) {
            while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), p) >= 0) {
                up.pop_back();
            }
            while (dn.size() > 1 && orientation(dn[dn.size() - 2], dn.back(), p) <= 0) {
                dn.pop_back();
            }
            up.push_back(p);
            dn.push_back(p);
        }
        v = dn;
        v.pop_back();
        reverse(up.begin(), up.end());
        up.pop_back();
        for (auto& p : up) {
            v.push_back(p);
        }
        if (v.size() == 2 && v[0] == v[1]) v.pop_back();
        return polygon(v);
    }
     //checks if convex or not
    bool is_convex() {
        bool s[3]; s[0] = s[1] = s[2] = 0;
        int n = p.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            s[sign(cross(p[j] - p[i], p[k] - p[i])) + 1] = 1;
            if (s[0] && s[2]) return 0;
        }
        return 1;
    }
    // -1 if strictly inside, 0 if on the polygon, 1 if strictly outside
    // polygon should be counter_clockwise.
    int point_inside_convex(const PT& x) {
        int n = p.size(), a, b, c;
        assert(n >= 3);
        PT g = (p[0] + p[n / 3] + p[n * 2 / 3]) / 3.0;
        int ag, cg;
        for (a = 0, b = n; a + 1 < b; ) {
            c = (a + b) / 2;
            ag = cross(p[a] - g, x - g);
            cg = cross(p[c] - g, x - g);
            if (cross(p[a] - g, p[c] - g) > 0) {
                if (ag > 0 and cg < 0) b = c; else a = c;
            } 
            else {
                if (ag < 0 and cg > 0) a = c; else b = c;
            }
        }
        b %= n;
        ag = cross(p[a] - x, p[b] - x);
        if (ag < 0) return 1;
        if (ag > 0) return -1;
        return 0;
    }
};


void solve(){

    int n; cin >> n;
    polygon poly;
    for(int i=0;i<n;i++){
        PT p; cin >> p.x >> p.y;
        poly.add(p);
    }
    cout << poly.area() << endl;

}

signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}