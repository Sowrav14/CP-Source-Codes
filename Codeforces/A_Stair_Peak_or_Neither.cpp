#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int a,b,c; cin >> a >> b >> c;

    if(a < b and b < c){
        cout << "STAIR" << endl;
        return;
    }

    if(a < b and b > c){
        cout << "PEAK" << endl;
        return;
    }
    cout << "NONE" << endl;

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