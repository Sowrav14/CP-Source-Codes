#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, s, x; cin >> n >> s >> x;
    vector<int> v(n+2, 0), pref(n+2, 0);
    map<int, vector<int>> mp;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
        mp[pref[i]].push_back(i);
    }

    vector<int> nextgt(n+2);
    int id = n + 1;
    for(int i=n;i>=1;i--){
        if(v[i] > x) id = i;
        nextgt[i] = id; 
    }
    vector<int> nextx(n+2);
    id = -1;
    for(int i=n;i>=1;i--){
        if(v[i] == x) id = i;
        nextx[i] = id; 
    }

    vector<pair<int,int>> valid(n+2);
    for(int i=1;i<=n;i++){
        int nextg = nextgt[i];
        int nextxx = nextx[i];
        
        if(nextxx == -1) {
            valid[i] = {-1, -1};
        } else if(nextg <= i){
            valid[i] = {-1, -1};
        } else if(nextg > nextxx){
            valid[i] = {nextxx, nextg - 1};
        } else if(nextg < nextxx){
            valid[i] = {-1, -1};
        }
    }

    // for(int i=1;i<=n;i++) cout << valid[i] << " "; cout << endl;

    int ans = 0;
    for(int i=1;i<=n;i++){
        int cur = pref[i-1];
        int req = s + cur;
        int l = valid[i].first;
        int r = valid[i].second;
        if(valid[i].first == -1) continue;

        // cout << "for i : " << i << endl;
        // cout << req << " " << j << endl;
        // for(auto it : mp[req]) cout << it << " "; cout << endl;

        int ll = lower_bound(mp[req].begin(), mp[req].end(), l) - mp[req].begin();
        int rr = upper_bound(mp[req].begin(), mp[req].end(), r) - mp[req].begin();
        
        int res = rr - ll;
        ans += res;
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