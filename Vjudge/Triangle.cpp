#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct point{
    int x,y;
};

point make_vector(point A, point B){
    point AB;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    return AB;
}

int dot_product(point a, point b){
    int ret = 0;
    ret += a.x * b.x;
    ret += a.y * b.y;
    return ret;
}

bool is_right_angle(point a, point b, point c){
    int del = a.x*b.y + b.x*c.y + c.x*a.y;
    del -= a.y*b.x + b.y*c.x + c.y*a.x;
    if(del == 0) return false;

    point ab = make_vector(a, b);
    point bc = make_vector(b, c);
    point ca = make_vector(c, a);

    int dot_a = dot_product(ab, bc);
    int dot_b = dot_product(bc, ca);
    int dot_c = dot_product(ca, ab);

    return (dot_a and dot_b and dot_c ? false : true);
}

point increment(point a, int flag, int value){
    if(flag) a.x = a.x + value;
    else a.y = a.y + value;
    return a;
}

void solve(){

    point a,b,c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    if(is_right_angle(a, b, c)){
        cout << "RIGHT" << endl;
    } else if(is_right_angle(increment(a, 1, 1), b, c)){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(increment(a, 0, 1), b, c)){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(a, increment(b, 1, 1), c)){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(a, increment(b, 0, 1), c)){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(a, b, increment(c, 1, 1))){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(a, b, increment(c, 0, 1))){
        cout << "ALMOST" << endl;
    } else if(is_right_angle(increment(a, 1, -1), b, c)){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(increment(a, 0, -1), b, c)){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(a, increment(b, 1, -1), c)){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(a, increment(b, 0, -1), c)){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(a, b, increment(c, 1, -1))){
        cout << "ALMOST" << endl;
    }  else if(is_right_angle(a, b, increment(c, 0, -1))){
        cout << "ALMOST" << endl;
    } else{
        cout << "NEITHER" << endl;
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