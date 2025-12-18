#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  Point operator + (const Point &p) const {
    return Point(x + p.x, y + p.y);
  }
  Point operator * (double c) const {
    return Point(x * c, y * c);
  }
};

double polygon_area(vector<Point> &poly) {
  int n = poly.size();
  double area = 0;
  for(int i = 0; i < n; i++) {
    Point &p1 = poly[i];
    Point &p2 = poly[(i + 1) % n];
    area += p1.x * p2.y - p2.x * p1.y;
  }
  return fabs(area) / 2.0;
}


void solve(){

  int n; cin >> n;
  vector<Point> P(n);
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    P[i] = Point(x, y);
  }

  vector<Point> R(n);
  for(int i = 0; i < n; i++) {
      Point &p1 = P[i];
      Point &p2 = P[(i+1)%n];
      R[i] = (p1 + p2) * 0.5;
  }

  cout << fixed << setprecision(10) << polygon_area(R) << "\n";

}


signed main(){
  Fast_IO()
  int t = 1;
  // cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}