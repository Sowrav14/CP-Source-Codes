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
    for(int i=1;i<n;i++){
        if(abs(v[i] - v[i-1]) <= 1){
            cout << 0 << endl;
            return;
        }
    }

    int ans = inf;
    for(int i=0;i<n;i++){
        if(i+2 < n){
            int mn = v[i+1], mx = v[i+1];
            for(int j=i+2;j<n;j++){
                mn = min(mn, v[j]);
                mx = max(mx, v[j]);
                if(v[i] >= mn-1 and v[i] <= mx+1){
                    ans = min(ans, j - i - 1);
                }
            }
        }
        if(i-2>=0){
            int mn = v[i-1], mx = v[i-1];
            for(int j=i-2;j>=0;j--){
                mn = min(mn, v[j]);
                mx = max(mx, v[j]);
                if(v[i] >= mn-1 and v[i] <= mx+1){
                    ans = min(ans, i - j - 1);
                }
            }
        }
    }
    if(ans == inf){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

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