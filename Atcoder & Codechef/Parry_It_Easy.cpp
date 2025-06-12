#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


bool check(int m, int x, int n, vector<int> &a, vector<int> &b){
    int y = x - m;
    if(y < 0) return false;
    int par = 0;
    for(int i=n-1;i>=0;i--){
        int yy = min(y+1, x);
        // cout << yy << endl;
        if(yy >= b[i]){
            par++;
            y = min(y+1, x);
        }
        if(y < a[i]) return false;
    }
    if(par >= m) return true;
    else return false;
}


void solve(){

    int n, x; cin >> n >> x;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    // cout << check(1, x, n, a, b) << endl;
    int ans = 0;
    int l = 0, r = 1e9 + 10;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m, x, n, a, b)){
            ans = m;
            l = m + 1;
        } else {
            ans = r = m - 1;
        }
    }
    cout << ans << endl;

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