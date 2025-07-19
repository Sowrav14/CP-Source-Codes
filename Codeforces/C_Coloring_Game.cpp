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
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i=2;i<n;i++){
        int z = a[i];
        for(int j=i-1;j>=0;j--){
            int y = a[j];
            int x1 = z - y;
            int x2 = a.back() - z - y;
            // if(i == 3 and j == 2){
            //     cout << a.back() << " " << z << ""
            // }
            int x = max(x1, x2);
            int it = upper_bound(a.begin(), a.end(), x) - a.begin();
            int res = max(0ll, j - it);
            // cout << i << " " << j << " " << x1 << " " << x2 << " " << res << endl;
            ans += res;
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