#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;



void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<int,int> m;
    vector<int> v(n);
    int tot = 0;
    for(int i=n-1;i>=0;i--){
        int x = tot - m[a[i]];
        if(a[i] != 0) x -= m[-a[i]];
        v[i] = x;
        tot++;
        m[a[i]]++;
    }
    // for(int i=0;i<n;i++) cout << v[i] << " "; cout << endl;
    map<int,int> tm;
    for(int i=0;i<n;i++) tm[a[i]] += v[i];
    // for(auto i : tm) cout << i.first << " " << i.second << endl;
    int ans = 0;
    for(int i=0;i<n;i++){
        tm[a[i]] -= v[i];
        // cout << tm[-a[i]] << " ";
        ans += tm[-a[i]];
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