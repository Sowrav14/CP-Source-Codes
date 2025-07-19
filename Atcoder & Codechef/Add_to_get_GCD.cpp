#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int a, b; cin >> a >> b;
    if(__gcd(a, b) > 1){
        cout << 0 << endl;
        return;
    }

    if(a%2 == 0 and b%2 == 1){
        cout << 1 << endl;
        return;
    }

    if(a%2 == 1 and b%2 == 0){
        cout << 1 << endl;
        return;
    }

    int x = a + 1;
    int y =  b + 1;
    if(__gcd(x, b) > 1){
        cout << 1 << endl;
        return;
    }
    if(__gcd(a, y) > 1){
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}