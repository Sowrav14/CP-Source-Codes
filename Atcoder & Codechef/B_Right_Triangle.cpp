#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int a1,b1; cin >> a1 >> b1;
    int a2,b2; cin >> a2 >> b2;
    int a3,b3; cin >> a3 >> b3;

    int d1 = (a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2);
    int d2 = (a1 - a3) * (a1 - a3) + (b1 - b3) * (b1 - b3);
    int d3 = (a2 - a3) * (a2 - a3) + (b2 - b3) * (b2 - b3);

    if(d1+d2 == d3 or d1+d3 == d2 or d2+d3 == d1){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

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