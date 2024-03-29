#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int a,b; cin >> a >> b;
    if(a%3 == 0){
        cout << "Possible" << endl;
        return;
    }
    if(b%3 == 0) {
        cout << "Possible" << endl;
        return;
    }
    a += b;
    if(a%3==0){
        cout << "Possible" << endl;
        return;
    }
    cout << "Impossible" << endl;

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