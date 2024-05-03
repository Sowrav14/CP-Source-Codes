#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int x; cin >> x;
    int y = 0, val = 0;

    for(int i=1;i<x;i++){
        int cur = __gcd(x, i) + i;
        if(cur > val){
            y = i;
            val = cur;
        }
    }

    cout << y << endl;

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