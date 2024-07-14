#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,m,k; cin >> n >> m >> k;

    for(int i=n;i>=k;i--){
        cout << i << " ";
    }
    for(int i=k-1;i>m;i--){
        cout << i << " ";
    }
    for(int i=1;i<=m;i++){
        cout << i << " ";
    } cout << endl;

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