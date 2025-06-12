#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int i=0;i<n;i++){
        int prev = -1;
        int l = i;
        int r = n - 1;
        for(int j=i;j<n;j++){
            int limit = (a[j] + 1) / 2 - 1;
            if(limit <= prev){
                if(a[j] > prev){
                    prev = a[j];
                } else {
                    r = j - 1;
                    break;
                }
            } else {
                prev = min(limit, prev + 1);
            }
        }
        ans += (r - l + 1);
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