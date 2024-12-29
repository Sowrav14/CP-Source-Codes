#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, p; cin >> n >> p;
    vector<int>l(n), r(n);
    for(int i=0;i<n;i++){
        cin >> l[i] >> r[i];
    }

    // non divisible by prime...
    vector<int>nd(n);
    for(int i=0;i<n;i++){
        int x = r[i]/p;
        int y = (l[i] - 1) / p;
        int tot = r[i] - l[i] + 1;
        nd[i] = tot - x + y;
    }
    vector<double>ev(n);
    for(int i=0;i<n;i++){
        int x = i;
        int y = (i + 1) % n;

        double EV = ((1.0 * nd[x]) / (r[x] - l[x] + 1)) * ((1.0 * nd[y]) / (r[y] - l[y] + 1));

        ev[x] += 1 - EV;
        ev[y] += 1 - EV;
    }

    double ans = 0;
    for(int i=0;i<n;i++){
        ans += ev[i];
    }

    cout << fixed << setprecision(10) << (double)(ans*1000.0) << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}