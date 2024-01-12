#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int a,b; cin >> a >> b;
    if((a+b)%2){
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}