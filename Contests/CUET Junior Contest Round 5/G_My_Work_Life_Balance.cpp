#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    map<pair<int,int>, int> mp;
    mp[{0, 0}] = -1;
    int ans = 0;
    int w = 0, l = 0, m = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'W') w++;
        else if(s[i] == 'L') l++;
        else m++;
        int x = w - l;
        int y = w - m;
        // cout << i << " --- " << w << " " << l << " " << m << endl;
        if(mp.find({x, y}) != mp.end()){
            ans = max(ans, i - mp[{x, y}]);
        }
        else {
            mp[{x, y}] = i;
        }
        // cout << i << " " << x << " " << y << " " << ans << endl;
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