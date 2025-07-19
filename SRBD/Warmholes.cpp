/**
 * @file Warmholes.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-06-17
 * @copyright Copyright (c) 2025
 * 
 * @problem: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/warmholes/problem
 * @tags: recursion, backtracking, bruteforce, greedy
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct hole {
    int sx, sy, dx, dy, c;
    hole(int sx, int sy, int dx, int dy, int c) : sx(sx), sy(sy), dx(dx), dy(dy), c(c) {} 
};

void solve(){

    int n; cin >> n;
    int ix, iy, fx, fy; cin >> ix >> iy >> fx >> fy;
    vector<hole> h;
    for(int i=0;i<n;i++){
        int sx, sy, dx, dy, c; cin >> sx >> sy >> dx >> dy >> c;
        h.push_back(hole(sx, sy, dx, dy, c));
    }
    int ans = inf;
    vector<int>vis(n, 0);
    function <void (int, int, int)> travel = [&](int x, int y, int cost) -> void {
        ans = min(ans, abs(fx - x) + abs(fy - y) + cost);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i] = 1;
                travel(h[i].sx, h[i].sy, cost + abs(h[i].dx - x) + abs(h[i].dy - y) + h[i].c);
                travel(h[i].dx, h[i].dy, cost + abs(h[i].sx - x) + abs(h[i].sy - y) + h[i].c);
                vis[i] = 0;
            }
        }
    };
    travel(ix, iy, 0);
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}