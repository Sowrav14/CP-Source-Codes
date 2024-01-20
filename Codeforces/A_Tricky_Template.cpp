#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    string a,b,c; cin >> a >> b >> c;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(a[i] != c[i] and b[i] != c[i]) flag = true;
    }
    cout << (flag ? "YES" : "NO") << endl;
    

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