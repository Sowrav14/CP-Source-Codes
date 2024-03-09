#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// Representing Points
struct point{
    int x,y;
};

// representing straight line if form of ax + by + c = 0.
struct straight_line{
    int a,b,c;
};

// return euclidean distance between two points.
double distance(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


// return straight line passing through two points in form of ax + by + c = 0;
straight_line eqn_of_straight_line(point a, point b){
    // (x - a.x)/(a.x - b.x) = (y - a.y)/(a.y - b.y)
    // x * (a.y - b.y) - a.x * (a.y - b.y) = y * (a.x - b.x) - a.y * (a.x - b.x)
    // (a.y - b.y) * x + (b.x - a.x) * y + a.y * (a.x - b.x) - a.x * (a.y - b.y) = 0;
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

// return x value of point (x, y) lies on straght line given y.
// return in form of x/y
pair<int,int> x_value_of_y_from_straight_line(straight_line st, int y){
    // ax + by + c = 0
    // ax = - c - by
    // x = (-c -by) / a

    pair<int,int>ret;
    ret.first = (-st.c - st.b * y);
    ret.second = st.a;
    int g = __gcd(ret.first, ret.second);
    ret.first /= g;
    ret.second /= g;

    return ret;
}
// return y value of point (x, y) lies on straght line given x.
// return in form of x/y
pair<int,int> y_value_of_x_from_straight_line(straight_line st, int x){
    // ax + by + c = 0
    // by = -c - ax
    // y = (-c - ax) / b

    pair<int,int>ret;
    ret.first = (-st.c - st.a * x);
    ret.second = st.b;
    int g = __gcd(ret.first, ret.second);
    ret.first /= g;
    ret.second /= g;

    return ret;
}

// both pair are fraction numbers 
// returns bigger from them.
pair<int,int> givebig(pair<int,int>a, pair<int,int>b){
    if(a.second == 0) return b;
    if(b.second == 0) return a;

    double x = (a.first * 1.0) / (a.second * 1.0);
    double y = (b.first * 1.0) / (b.second * 1.0);

    if(x > y) return a;
    else return b;
}

// return distance on basis of x as y is same
// (a/b) - (c/d)
// ((a*d - c*b) / bd)
// return in form of x/y.
pair<int,int> fraction_subtract(pair<int,int> a, pair<int,int> b){
    pair<int,int>ret;
    ret.first = (a.first * b.second - b.first * a.second);
    ret.second = (b.second * a.second);

    int g = __gcd(ret.first, ret.second);
    ret.first /= g;
    ret.second /= g;

    return ret;
    
}



void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];


    vector<int>pref(n+1), suf(n+1);
    stack<pair<int,int>>st;
    st.push({INT_MAX, 0});
    for(int i=1;i<=n;i++){
        while(st.size()){
            if(st.top().first > v[i]){
                pref[i] = st.top().second;
                break;
            }
            st.pop();
        }
        st.push({v[i], i});
    }

    stack<pair<int,int>>stt;
    stt.push({INT_MAX, n+1});
    for(int i=n;i>=1;i--){
        while(stt.size()){
            if(stt.top().first > v[i]){
                suf[i] = stt.top().second;
                break;
            }
            stt.pop();
        }
        stt.push({v[i], i});
    }


    // for(int i=1;i<=n;i++) cout << pref[i] << " "; cout << endl;
    // for(int i=1;i<=n;i++) cout << suf[i] << " " ; cout << endl;

    pair<int,int>ans = {0, 1};
    for(int i=1;i<=n;i++){

        int left = pref[i];
        int right = suf[i];

        if(left != 0){
            // straight line through point (left, v[left]), (left+1, v[left+1])
            point p1 = {left, v[left]};
            point p2 = {left+1, v[left+1]};
            straight_line st = eqn_of_straight_line(p1, p2);
            pair<int,int>res = x_value_of_y_from_straight_line(st, v[i]);
            res = fraction_subtract({i, 1}, res);
            ans = givebig(ans, res);
        }
        if(right != n+1){
            // straight line through point (right, v[right]), (right-1, v[right-1])
            point p1 = {right, v[right]};
            point p2 = {right-1, v[right-1]};
            straight_line st = eqn_of_straight_line(p1, p2);
            pair<int,int> res = x_value_of_y_from_straight_line(st, v[i]);
            res = fraction_subtract(res, {i, 1});
            ans = givebig(res, ans);
        }

    }

    if(ans.first == 0){
        cout << 0 << endl;
    } else{
        cout << ans.first << "/" << ans.second << endl;
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