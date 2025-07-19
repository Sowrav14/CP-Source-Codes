#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    int event = 0;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) event += b[i];

    int l = 0, r = inf;
    for(int i=0;i<n;i++) l = max(l, a[i]);
    int ans = inf;
    while(l <= r){
        int m = (l + r) / 2;
        int extra = 0, rem = 0;
        for(int i=0;i<n;i++){
            int x = a[i];
            int add = m - x;
            if(add <= b[i]){
                extra += 0;
                rem += b[i] - add;
            } else if((add - b[i])%2){
                extra += add - b[i] + 1;
                rem += 1;
            } else {
                extra += add - b[i];
                rem += 0;
            }
        }

        if(rem * 2 <= extra){
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