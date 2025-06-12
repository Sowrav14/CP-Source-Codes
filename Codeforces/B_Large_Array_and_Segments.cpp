#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n, 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=n-2;i>=0;i--){
        a[i] = a[i] + a[i+1];
    }
    int l = 0, r = n * k - 1;
    int ans = -1;
    while(l <= r){
        int m = (l + r) / 2;

        int id = m % n;
        int left = m / n;
        int right = k - left - 1;
        int sum = a[id] + (right * a[0]);

        // cout << m << " " << left << " " << right << " " << id  << " " << sum << endl;
        if(sum >= x){
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << ans + 1 << endl;

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