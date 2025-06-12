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
    vector<int> a(n), c(n);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'A') cnt++;
        if(s[i] == 'C') cnt = 0;
        a[i] = cnt;
    }
    cnt = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == 'C') cnt++;
        if(s[i] == 'A') cnt = 0;
        c[i] = cnt;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'B'){
            ans += max(a[i], c[i]);
        }
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