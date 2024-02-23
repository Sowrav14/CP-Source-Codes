#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const double eps = 1e-12;
const double inf = 1e15;

struct points{
    double x,y;
    double vx, vy;
    double t1, t2;
};
vector<points>p;



void solve(){

    double n; cin >> n;
    double x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2;
    x1 += eps; x2 -= eps;
    y1 += eps; y2 -= eps;
    p.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i].x >> p[i].y >> p[i].vx >> p[i].vy;
    }
    bool flag = true;
    // determining time interval between the triangle.
    for(int i=1;i<=n;i++){
        // time based on x coordinate.
        double t11, t21;
        if(p[i].vx > 0){
            if(p[i].x > x2) flag = false;
            t11 = p[i].x < x1 ? (x1 - p[i].x) / (p[i].vx * 1.0) : 0 ;
            t21 = (x2 - p[i].x) / (p[i].vx * 1.0);
        } else if(p[i].vx < 0){
            if(p[i].x < x1) flag = false;
            t11 = p[i].x > x2 ? (p[i].x- x2) / (abs(p[i].vx) * 1.0) : 0 ;
            t21 = (p[i].x - x1) / (abs(p[i].vx) * 1.0);
        } else {
            if(p[i].x >= x1 and p[i].x <= x2) {
                t11 = 0;
                t21 = inf;
            } else {
                flag = false;
            }
        }
        // time based on y coordinate.
        double t12, t22;
        if(p[i].vy > 0){
            if(p[i].y > y2) flag = false;
            t12 = p[i].y < y1 ? (y1 - p[i].y) / (p[i].vy * 1.0) : 0 ;
            t22 = (y2 - p[i].y) / (p[i].vy * 1.0);
        } else if(p[i].vy < 0){
            if(p[i].y < y1) flag = false;
            t12 = p[i].y > y2 ? (p[i].y- y2) / (abs(p[i].vy) * 1.0) : 0 ;
            t22 = (p[i].y - y1) / (abs(p[i].vy) * 1.0);
        } else {
            if(p[i].y >= y1 and p[i].y <= y2) {
                t12 = 0;
                t22 = inf;
            } else {
                flag = false;
            }
        }

        p[i].t1 = max(t11, t12);
        p[i].t2 = min(t21, t22);
    }

    double ansmn = 0, ansmx = inf;
    for(int i=1;i<=n;i++){
        // cout << p[i].t1 << " " << p[i].t2 << endl;
        if(p[i].t1 > p[i].t2) flag = false;
        else {
            ansmn = max(ansmn, p[i].t1);
            ansmx = min(ansmx, p[i].t2);
        }
    }
    if(ansmx < ansmn) flag = false;

    if(flag){
        cout << fixed << setprecision(10) << ansmn << endl;
    } else{
        cout << -1 << endl;
    }
   
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