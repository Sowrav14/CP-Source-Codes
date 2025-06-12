#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 998244353;
const int inf = 1e12;

int A_pow_B(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (1ll * ret%M * a%M) % M;
        }
        a = (1ll * a%M * a%M) % M;
        b >>= 1;
    }
    return ret;
}

void solve(){

    int n; cin >> n;
    
    if(n%2){
        cout << A_pow_B(2, n-1) << endl;
    } else {
        cout << (3 * A_pow_B(2, n-2))%M << endl;
    }

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