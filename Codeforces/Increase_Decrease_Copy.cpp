#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>a(n), b(n+1);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<=n;i++) cin >> b[i];

    int res = 0;

    for(int i=0;i<n;i++){
        res += abs(a[i] - b[i]);
    }

    int ans = 1e16;
    for(int i=0;i<n;i++){
        int cur = abs(a[i] - b[i]);

        int tr = abs(a[i] - b.back()) + abs(b[i] - b.back());
        int trr = abs(a[i] - b[i]) + abs(a[i] - b.back());
        int t = abs(a[i] - b[i]) + abs(b[i] - b.back());

        int temp = res - cur;
        temp += min(min(t, tr),trr) + 1;
        // cout << temp << endl;
        ans = min(ans, temp);
    }

    cout << ans << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}