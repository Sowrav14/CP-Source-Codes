#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int a,b; cin >> a >> b;
    if(a > b) swap(a,b);
    if(a == 1){
        cout << b * b << endl;
        return;
    }
    
    int x = __gcd(a,b);
    int aa = b / x;
    if(x == a){
        cout << b * aa << endl;
        return;
    }
    cout << a * aa << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}