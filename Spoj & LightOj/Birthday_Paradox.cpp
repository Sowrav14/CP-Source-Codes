#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    double ans = 1;
    for(int i=1;i<=n;i++){
        ans *= (n - i)/(1.0 * n);
        if(ans <= 0.5){
            cout << i << endl;
            return;
        }
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ": ";
        solve();
    }
}