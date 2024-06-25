#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'a'){
            cnt++;
        } else{
            if(cnt >= 2){
                ans += cnt;
            }
            cnt = 0;
        }
    }
    if(cnt >= 2) ans += cnt;
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}