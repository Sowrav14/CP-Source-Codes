#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
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

    int a, b, k; cin >> a >> b >> k;
    int n = (((a - 1)%M * k%M)%M + 1%M)%M;
    // int m = (((b - 1)%M * k%M * nCr(n, a)%M)%M + 1%M)%M;
    // n is big here so no nCr
    // use nCr = (n * n-1 *...* n-r+1) / (1 * 2 * ... * r)
    int m = ((b - 1)%M * k%M)%M;
    for(int i=0;i<a;i++){
        m = (m%M * (n-i)%M)%M;
        m = (m%M * A_pow_B(a-i, M-2)%M)%M;
    }
    m = (m + 1)%M;
    cout << n << " " << m << endl;

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