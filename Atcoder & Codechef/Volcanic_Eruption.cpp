#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e15;


void solve(){

    int n,m; cin>> n >> m;

    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int>prev(n),next(n);

    int mx = inf;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            mx = 0;
        }
        else{
            mx = max(mx, a[i]);
            prev[i] = mx;
        }
    }

    mx = inf;
    for(int i=n-1;i>=0;i--){
        if(a[i] == 0){
            mx = 0;
        } else{
            mx = max(mx, a[i]);
            next[i] = mx;
        }
    }
    // for(int i=0;i<n;i++) cout << prev[i] << " "; cout << endl;
    // for(int i=0;i<n;i++) cout << next[i] << " "; cout << endl;

    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int a = ceil(prev[i] / (m * 1.0));
        int b = ceil(next[i] / (m * 1.0));

        ans[i] = min(a, b);
    }

    for(int i=0;i<n;i++) cout << ans[i] << " "; cout << endl;

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