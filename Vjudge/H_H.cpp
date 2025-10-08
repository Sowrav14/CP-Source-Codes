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
    string s; cin >> s;

    int p = -1;
    for(int i=0;i<n;i++) {
        if(s[i] == '0' and s[(i-1+n)%n] == '1') p = i;
    }
    if(p == -1){
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n);
    int l = 0, r = n-1;
    for(int i=p;i<n;i++){
        if(s[i] == '0') ans[i] = l++;
        else ans[i] = r--;
    }
    for(int i=0;i<p;i++){
        if(s[i] == '0') ans[i] = l++;
        else ans[i] = r--;
    }
    for(int i=0;i<n;i++) cout << ans[i] << " "; cout << endl;

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