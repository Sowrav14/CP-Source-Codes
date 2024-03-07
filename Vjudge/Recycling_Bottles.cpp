#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct point{
    double x,y;
};

struct dis{
    double fst, sd, rb;
};

void input(point &t){
    cin >> t.x >> t.y;
}

double distance(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void solve(){

    point a,b,r;
    input(a);
    input(b);
    input(r);

    int n; cin >> n;
    vector<point>v(n);
    for(int i=0;i<n;i++) input(v[i]);
    double ans = 0;
    vector<dis>d(n);

    // at least one of them have to go to one of botlles 
    // so that distance travelled is minimized.

    double mx = INT_MIN, secmx = INT_MIN;
    int mxi = -1, secmxi = -1;
    double mmx = INT_MIN, secmmx = INT_MIN;
    int mmxi = -1, secmmxi = -1;

    for(int i=0;i<n;i++){
        d[i].fst = distance(a, v[i]);
        d[i].sd = distance(b, v[i]);
        d[i].rb = distance(r, v[i]);
        ans += d[i].rb * 2.0;
        // cout << d[i].fst << " " << d[i].sd << " " << d[i].rb << endl;

        double la = d[i].rb - d[i].fst;
        if(la >= mx){
            secmx = mx;
            secmxi = mxi;
            mx = la;
            mxi = i;
        } else if(la >= secmx){
            secmx = la;
            secmxi = i;
        }


        double lb = d[i].rb - d[i].sd;
        if(lb >= mmx){
            secmmx = mmx;
            secmmxi = mmxi;
            mmx = lb;
            mmxi = i;
        } else if(lb >= secmmx){
            secmmx = lb;
            secmmxi = i;
        }
        
    }

    // cout << mx << " " << secmx << endl;
    // cout << mxi << " " << secmxi << endl;
    // cout << mmx << " " << secmmx << endl;
    // cout << mmxi << " " << secmmxi << endl;

    if(mxi != mmxi){
        ans -= (mx + mmx);
    } else if(secmmx < 0){
        ans -= 
    }

    cout << fixed << setprecision(12) << ans << endl;

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