#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k, x; cin >> n >> k >> x;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> pref(n+1, 0);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + a[i];
    }

    int ans = -1;
    int lo = 1, hi = n;

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int s = k - (n - mid);
        if(s < 0) s = 0;

        int sum = 0;
        if(s > 0){
            int start = n - mid;
            sum = pref[start + s] - pref[start];
        }

        if(sum >= x){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
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
