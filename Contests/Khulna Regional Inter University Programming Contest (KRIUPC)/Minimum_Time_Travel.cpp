#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e19;

#define pii pair<int,int>
#define x first
#define y second

int cross(pii a, pii b, pii c) {
   return (b.y-a.y) * (c.x-a.x) - (b.x-a.x) * (c.y-a.y);
}

void solve(){

    int n; cin >> n;
    vector<pii>p;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        p.push_back({x, y});
    }

    int ans = inf;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int res = abs(cross(p[i], p[j], p[k]));
                if(res != 0) ans = min(ans, res);
            }
        }
    }
    cout << fixed << setprecision(10) << (double)(ans/2.0) << endl;

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