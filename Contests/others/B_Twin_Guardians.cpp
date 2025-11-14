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
    if(a + 2 != b) return cout << "N" << endl, void();
    if(a == 1) return cout << "N" << endl, void();
    for(int i=2;i<a;i++){
        if(a % i == 0){
            cout << "N" << endl;
            return;
        }
    }
    for(int i=2;i<b;i++){
        if(b % i == 0){
            cout << "N" << endl;
            return;
        }
    }
    cout << "Y" << endl;

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