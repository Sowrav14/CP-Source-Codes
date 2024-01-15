#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    int a = 0, b = 0;
    string p,q; cin >> p >> q;
    for(int i=0;i<n;i++){
        if(p[i] == '1' and q[i] == '0') a++;
        if(p[i] == '0' and q[i] == '1') b++;

    }

    cout << max(a, b) << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}