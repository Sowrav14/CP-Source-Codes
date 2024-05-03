#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        char c; cin >> c;
        if(c == 'U') cnt++;
    }

    cout << (cnt%2 ? "YES" : "NO") << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}