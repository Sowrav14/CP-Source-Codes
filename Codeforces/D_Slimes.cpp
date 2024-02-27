#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

/*

    Having problem in checking is there is two or more distinct 
    in range [l, r]

 */



void solve(){

    int n; cin >> n;
    vector<int>v(n+1, 0), pref(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }
    if(n == 1){
        cout << -1 << endl;
        return;
    }
    vector<int>dist(n+1, 0), ans(n+1, n+1);
    dist[1] = 1;
    for(int i=2;i<=n;i++){
        if(v[i] == v[i-1]){
            dist[i] = dist[i-1];
        } else{
            dist[i] = dist[i-1] + 1;
        }
    }

    // for(int i=1;i<=n;i++) cout << pref[i] << " "; cout << endl;
    // for(int i=1;i<=n;i++) cout << dist[i] << " "; cout << endl;

    for(int i=1;i<=n;i++){

        if((i-1>0 and v[i] < v[i-1]) or (i+1<=n and v[i] < v[i+1])){
            cout << 1 << " ";
            continue;
        }
        
        // check right.
        int l = i + 1, r = n;
        int res = n + 1;
        while(l <= r){
            int m = (l + r) / 2;
            int sum = pref[m] - pref[i];
            int el = dist[m] - dist[i+1];
            // cout << sum << " " << el << " " << i << " " << m << endl;
            if(sum > v[i] and (el >= 1 or m - i == 1)){
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        // cout << res << endl;
        // res = res - i + 1;
        // ans[i] = min(ans[i], res);
        if(res != n+1){
            res = res - i;
            ans[i] = min(ans[i], res);
        }

        l = 1, r = i - 1;
        res = n + 1;
        while(l <= r){
            int m = (l + r) / 2;
            int sum = pref[i-1] - pref[m-1];
            int el = dist[i-1] - dist[m];
            // cout << sum << " " << el << " " << i << " " << m << endl;
            if(sum > v[i] and (el >= 1 or i-m == 1)){
                res = m;
                l = m + 1;
            } else{
                r = m - 1;
            }
        }
        // cout << res << endl;
        // res = i - res + 1;
        // ans[i] = min(ans[i], res);
        if(res != n+1){
            res = i - res;
            ans[i] = min(ans[i], res);
        }

        if(ans[i] == n+1) ans[i] = -1;
        cout << ans[i] << " ";

    } cout << endl;

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