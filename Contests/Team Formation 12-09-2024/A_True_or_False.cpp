#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    char a, b; cin >> a >> b;

    if(a == 'H' and b == 'H'){
        cout << 'H' << endl;
    } else if(a == 'H' and b == 'D'){
        cout << 'D' << endl;
    } else if(a == 'D' and b == 'D'){
        cout << 'H' << endl;
    } else {
        cout << 'D' << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}