#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    vector<pair<int,int>>v(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v[i].first = x;
        sum += x;
    }
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v[i].second = x;
    }

    sort(v.begin(), v.end());

    int mn = v[0].first;
    int secmn = v[1].first;
    int mx = v.back().first;
    int secmx = v[n-2].first;

    int ans = sum - mx - mn;
    if(v[0].second > mx){
        ans = max(ans, sum - mn - secmn);
    } else if(v[0].second < secmn){
        ans = max(ans, sum - mn - mx);
    } else {
        ans = max(ans, sum + v[0].second - secmn - mx - mn);
    }


    if(v.back().second > secmx){
        ans = max(ans, sum - mn - mx);
    } else if(v.back().second < mn){
        ans = max(ans, sum - mx - secmx);
    } else {
        ans = max(ans, sum - mn - secmx - mx + v.back().second);
    }

    for(int i=1;i<=n-2;i++){
        int x = v[i].first;
        int y = v[i].second;

        if(y < mn){
            ans = max(ans, sum - x - mx);
        } else if(y > mx){
            ans = max(ans, sum - mn - x);
        } else{
            ans = max(ans, sum - x - mn - mx + y);
        }
    }

    cout << ans << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}