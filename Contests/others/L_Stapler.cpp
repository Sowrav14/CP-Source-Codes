#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = 1e12;

struct Point { int x,y; };

bool onSegment(Point p, Point q, Point r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
    q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) return true;
  return false;
}

int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;
  return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4) return true;
  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  return false;
}

bool insideRectInclusive(Point p, int xl, int yl, int xr, int yr) {
  return (p.x >= xl && p.x <= xr && p.y >= yl && p.y <= yr);
}

void solve() {
  int xl, yl, xr, yr;
  cin >> xl >> yl >> xr >> yr;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  Point s1 = {x1, y1}, s2 = {x2, y2};
  // rectangle corners
  Point r1 = {xl, yl}, r2 = {xr, yl}, r3 = {xl, yr}, r4 = {xr, yr};

  if (insideRectInclusive(s1, xl, yl, xr, yr) || insideRectInclusive(s2, xl, yl, xr, yr)) {
    cout << "STOP\n";
    return;
  }
  if (doIntersect(s1, s2, r1, r2) || doIntersect(s1, s2, r3, r4) ||
    doIntersect(s1, s2, r1, r3) || doIntersect(s1, s2, r2, r4)) {
    cout << "STOP\n";
  } else {
    cout << "OK\n";
  }
}

signed main() {
  Fast_IO()
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
