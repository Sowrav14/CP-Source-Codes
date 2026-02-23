#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const double PI = acos(-1);


double deg(double rad){
    return rad * 180.0 / PI;
}


double getAngle(int x, int y){
    double ang = deg(atan2(y, x));
    if(ang < 0) ang += 360;
    ang = 360 - ang;
    if(ang >= 360) ang -= 360;
    return ang;
}

void solve(){
    int n,q; cin >> n >> q;
    vector<pair<int,int>> points(n);
    vector<double> angles(n);
    map<double,int> cnt;

    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        points[i] = {x,y};
        double a = getAngle(x,y);
        angles[i] = a;
        cnt[a]++;
    }

    vector<double> sang;
    for(auto &p: cnt) sang.push_back(p.first);
    sort(sang.begin(), sang.end());

    int m = sang.size();

    vector<int> pref(m);
    for(int i=0;i<m;i++){
        pref[i] = cnt[sang[i]];
        if(i>0) pref[i] += pref[i-1];
    }

    vector<double> dupAngles;
    vector<int> dupPref;
    for(int i=0;i<m;i++){
        dupAngles.push_back(sang[i]);
        dupPref.push_back(pref[i]);
    }
    for(int i=0;i<m;i++){
        dupAngles.push_back(sang[i]+360);
        dupPref.push_back(pref[i] + pref.back());
    }

    while(q--){
        int u,v; cin >> u >> v;
        double a1 = angles[u-1];
        double a2 = angles[v-1];

        if(abs(a1 - a2) < 1e-12){
            cout << cnt[a1] << endl;
            continue;
        }

        auto it1 = lower_bound(dupAngles.begin(), dupAngles.end(), a1);
        double target = (a2 >= a1 ? a2 : a2 + 360);
        auto it2 = upper_bound(dupAngles.begin(), dupAngles.end(), target) - 1;

        int idx1 = it1 - dupAngles.begin();
        int idx2 = it2 - dupAngles.begin();

        int res = dupPref[idx2] - (idx1>0 ? dupPref[idx1-1] : 0);
        cout << res << endl;
    }
}

signed main(){
    Fast_IO()
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
