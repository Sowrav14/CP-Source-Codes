#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    vector<int>pref(n+1, 0),suf(n+1, 0);
    pref[2] = 1;
    for(int i=2;i<n;i++){
        int cur = v[i];
        int prev = v[i-1];
        int next = v[i+1];
        if(next-cur < cur-prev){
            pref[i+1] = pref[i] + 1;
        } else {
            pref[i+1] = pref[i] + next - cur;
        }
    }

    suf[n-1] = 1;
    for(int i=n-1;i>1;i--){
        int cur = v[i];
        int next = v[i-1];
        int prev = v[i+1];

        if(cur-next < prev-cur){
            suf[i-1] = suf[i] + 1;
        } else{
            suf[i-1] = suf[i] + cur - next;
        }
    }

    // for(int i=1;i<=n;i++) cout << pref[i] << " "; cout << endl;
    // for(int i=1;i<=n;i++) cout << suf[i] << " "; cout << endl;

    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        if(l <= r){
            cout << pref[r] - pref[l] << endl;
        } else {
            cout << suf[r] - suf[l] << endl;
        }
    }

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}