#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector<int>points;

// Representing Points
struct point{
    int x,y;
};

// representing straight line if form of ax + by + c = 0.
struct straight_line{
    int a,b,c;
};


// return straight line passing through two points in form of ax + by + c = 0;
// (x - a.x)/(a.x - b.x) = (y - a.y)/(a.y - b.y)
// x * (a.y - b.y) - a.x * (a.y - b.y) = y * (a.x - b.x) - a.y * (a.x - b.x)
// (a.y - b.y) * x + (b.x - a.x) * y + a.y * (a.x - b.x) - a.x * (a.y - b.y) = 0;
straight_line eqn_of_straight_line(point a, point b){
    straight_line st;
    st.a = (a.y - b.y);
    st.b = (b.x - a.x);
    st.c = a.y * (a.x - b.x) - a.x * (a.y - b.y);
    int g = __gcd(st.a, __gcd(st.b, st.c));
    st.a /= g;
    st.b /= g;
    st.c /= g;

    return st;
}

bool is_on_straight_line(straight_line st, point a){
    return ((st.a * a.x + st.b * a.y + st.c) == 0);
}

bool check(point a, point b, point c){
    straight_line ab = eqn_of_straight_line(a, b);
    straight_line cx;
    cx.a = ab.a, cx.b = ab.b, cx.c = -(ab.a * c.x + ab.b * c.y);

    for(int i=1;i<=n;i++){
        point t; t.x = i, t.y = points[i];
        if(is_on_straight_line(ab, t)){
            continue;
        } else if(is_on_straight_line(cx, t)){
            continue;
        } else{
            return false;
        }
    }
    return true;
}

void solve(){

    cin >> n;
    points.resize(n+1, 0);
    for(int i=1;i<=n;i++) cin >> points[i];

    // fix a, b, c
    point a,b,c;
    a.x = 1, a.y = points[1];
    b.x = 2, b.y = points[2];
    c.x = 0, c.y = 0;
    straight_line ab = eqn_of_straight_line(a, b);
    for(int i=3;i<=n;i++){
        point t;
        t.x = i, t.y = points[i];
        if(is_on_straight_line(ab, t)){
            continue;
        } else{
            c = t;
            break;
        }
    }

    if(c.x == 0){
        cout << "No" << endl;
        return;
    }

    if(check(a, b, c)){
        cout << "Yes" << endl;
    } else if(check(b, c, a)){
        cout << "Yes" << endl;
    } else if(check(c, a, b)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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