#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e13;

int n;
vector<int>a, c;
int h;

bool check(int k){
    int tot = 0;
    for(int i=0;i<n;i++){
        int x = (k - 1) / c[i];
        x++;
        // cout << x << " " << a[i] << endl;
        int he = x * a[i];
        if(he > N) return true;
        tot += he;
        if(tot > N) return true;
    }
    // cout << tot << endl;
    return tot >= h;
}

void solve(){

    cin >> h >> n;
    a.clear(); a.resize(n);
    c.clear(); c.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> c[i];

    // cout << check(3) << endl;

    int l = 1, r = inf;
    int ans = inf;
    while(l <= r){
        int m = (l + r) / 2;

        if(check(m)){
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
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