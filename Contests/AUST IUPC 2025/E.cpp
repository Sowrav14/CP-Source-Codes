#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    string s; cin >> s;
    int n = s.size();

    vector<int> a, b, c;
    for(int i=0;i<n;i++) {
        if(s[i] == 'a') a.push_back(i);
        else if(s[i] == 'b') b.push_back(i);
        else c.push_back(i);
    }

    int ans = inf;
    for(int i=0;i<n;i++){
        int x = lower_bound(a.begin(), a.end(), i) - a.begin();
        int y = lower_bound(b.begin(), b.end(), i) - b.begin();
        int z = lower_bound(c.begin(), c.end(), i) - c.begin();
        if(x == a.size() or y == b.size() or z == c.size()) continue;
        int j = max({a[x], b[y], c[z]});
        ans = min(ans, j - i + 1);
    }
    cout << ans << "\n";

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}