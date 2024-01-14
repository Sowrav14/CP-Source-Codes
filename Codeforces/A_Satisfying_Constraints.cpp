#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    vector<int>v;
    int l = 0, r = INT64_MAX;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        if(x == 1) l = max(l, y);
        if(x == 2) r = min(r, y);
        if(x == 3) v.push_back(y);
    }
    int ans = r - l + 1;
    // cout << l << " " << r << endl;
    for(auto i : v){
        if(i > r) continue;
        if(i < l) continue;
        ans--;
    }
    cout << max(0ll, ans) << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}