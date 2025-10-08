#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e18;


void solve(){

    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    vector<int> prea(n+1, 0), preb(m+1, 0);
    for(int i=0;i<n;i++) prea[i+1] = prea[i] + a[i];
    for(int i=0;i<m;i++) preb[i+1] = preb[i] + b[i];

    while(q--){
        int x, y, z; cin >> x >> y >> z;

        if(z == 0){
            cout << 0 << endl;
            continue;
        }

        int l = max(0ll, z - y);
        int r = min(x, z);
        if(l > r){
            cout << 0 << endl;
            continue;
        }

        int ans = 0;
        while(l <= r){
            int mid = (r - l) / 3;
            int m1 = l + mid;
            int m2 = r - mid;

            int sum1 = (m1 <= n and z - m1 <= m) ? prea[m1] + preb[z - m1] : -inf;
            int sum2 = (m2 <= n && z - m2 <= m) ? prea[m2] + preb[z - m2] : -inf;

            if(sum1 >= sum2){
                ans = max(ans, sum1);
                r = m2 - 1;
            } else {
                ans = max(ans, sum2);
                l = m1 + 1;
            }
        }
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