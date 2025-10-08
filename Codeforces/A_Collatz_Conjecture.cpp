#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int get(int n, int k){
    for(int i=0;i<k;i++){
        if(n%2){
            n = 3 * n + 1;
        } else {
            n = n / 2;
        }
    }
    return n;
}

void solve(){

    int k, x; cin >> k >> x;
    for(int i=0;i<k;i++){
        x *= 2;
    }
    cout << x << endl;

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