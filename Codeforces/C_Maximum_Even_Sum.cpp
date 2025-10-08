#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int a, b; cin >> a >> b;
    if(b%2){
        if(a%2){
            cout << a * b + 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    int cnt = 0;
    int temb = b;
    while(temb%2 == 0){
        temb /= 2;
        cnt++;
    }
    if(a%2 and cnt == 1) return cout << -1 << endl, void();
    int t = a%2 ? 2 : 1;
    cout << max(a*t+b/t, a*(b/2)+2) << endl;

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