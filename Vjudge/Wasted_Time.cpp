#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Point{
    int x,y;
    Point(){}
    Point(int x_, int y_) : x(x_), y(y_) {}
};

float distance(Point a, Point b){
    return sqrtf((a.x - b.x) * 1.0 * (a.x - b.x) + (a.y - b.y) * 1.0 * (a.y - b.y));
}

void solve(){

    int n,k; cin >> n >> k;
    float ans = 0;
    Point last;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        Point cur(x, y);
        if(i != 1){
            ans += distance(last, cur);
        }
        last = cur;
    }

    ans *= k;
    ans /= 50.0;

    cout << fixed << setprecision(9) << ans << endl;
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