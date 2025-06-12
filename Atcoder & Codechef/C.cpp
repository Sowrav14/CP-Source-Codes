#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> a(n), b(n);;
    for(int i=1;i<n-1;i++){
        if(v[i] > v[i-1] and v[i] > v[i+1]){
            a[i] = 1;
        } else {
            a[i] = 0;
        }

        if(v[i] < v[i-1] and v[i] < v[i+1]){
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }

    for(int i=1;i<n;i++){
        a[i] += a[i-1];
        b[i] += b[i-1];
    }
    // for(int i=0;i<n;i++){
    //     cout << a[i] << " ";
    // } cout << endl;
    // for(int i=0;i<n;i++){
    //     cout << b[i] << " ";
    // } cout << endl;
    int ans = 0;
    for(int i=0;i+3<n;i++){
        if(v[i] >= v[i+1]) continue;
        // cout << "for " << i << endl;
        int x = lower_bound(a.begin(), a.end(), a[i] + 1) - a.begin();
        if(x == n) continue;
        int y = lower_bound(b.begin(), b.end(), b[i] + 1) - b.begin();
        if(y == n) continue;
        // cout << "x: " << x << " y: " << y << endl;
        int la = max(x, y) + 1;
        x = upper_bound(a.begin(), a.end(), a[i] + 1) - a.begin();
        y = upper_bound(b.begin(), b.end(), b[i] + 1) - b.begin();
        // cout << "x: " << x << " y: " << y << endl;
        int lb = min(x, y);
        if(lb == n) lb = n - 1;
        if(la > lb) continue;
        // cout << i << " " << la << " " << lb << endl;
        ans += (lb - la + 1);
        
    }
    cout << ans << endl;

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