#include<bits/stdc++.h>
using namespace std;
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi acos(-1)

// Representing Points
struct point{
    float x,y;
};

// representing straight line if form of ax + by + c = 0.
struct straight_line{
    float a,b,c;
};

// return radian angle taking degree angle.
float degree_to_radian(float angle){
    angle *= pi;
    angle /= 180;
    return angle;
}


point xxxxx(float r, float d){
    point ret;
    ret.x = (2*r*r - d*d) / (2*r);

    ret.y = (r*r - ret.x*ret.x);
    ret.y = sqrtf(ret.y);

    return ret;
}



void solve(){

    float r, a; cin >> r >> a;

    float BC = 2 * r * cos(degree_to_radian(a));
    float BN = 2 * r * cos(degree_to_radian(a/2));

    point B = {r, 0};
    point C = xxxxx(r, BC);
    point N = xxxxx(r, BN);
    point D;
    D.x = (B.x + C.x) / 2;
    D.y = (B.y + C.y) / 2;

    float ans = (D.y - N.y) / (D.x - N.x);
    ans *= (-D.x);
    ans += D.y;

    cout << fixed << setprecision(10) << ans  << endl;

}


signed main(){
    Fast_IO()
    float t = 1;
    cin >> t;
    for(float i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}