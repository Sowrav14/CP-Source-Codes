#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string a, b; cin >> a >> b;

    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += (a[i] != b[i]);
    }
    // cout << cnt << endl;
    if(cnt%2){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

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