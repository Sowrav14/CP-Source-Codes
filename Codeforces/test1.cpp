#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    cout << (1ll << 59) << endl;
    cout << floor(log2(576460752303423487)) << endl;
    int n = 576460752303423487;
    int i = 0;
    while(1){
        if(n > (1ll << i)){
            i++;
        } else {
            i--;
            break;
        }
    }
    cout << i << endl;

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