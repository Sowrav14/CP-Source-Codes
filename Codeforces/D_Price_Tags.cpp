#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e18;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int mx = *max_element(v.begin(), v.end());
    if(mx == 1) return cout << n << endl, void();
    vector<int> pref(mx+1, 0), cnt(mx+1, 0);
    for(int i=0;i<n;i++) pref[v[i]]++, cnt[v[i]]++;
    for(int i=1;i<=mx;i++) pref[i] += pref[i-1];

    int ans = -inf;
    for(int x=2;x<=mx;x++){
        int res = 0;
        for(int p=1;p<=mx;p++){
            int l = x * (p - 1);
            int r = min(mx, p * x);
            if(l > mx) break;

            int need = pref[r] - pref[l];
            res += need * p;
            res -= k * max(0ll, need - cnt[p]);
        }
        ans = max(ans, res);
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