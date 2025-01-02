#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

// Big Mod
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
    
    // symmetric configurations by rotating (number of cell can be colored)
    int n0 = n * n;
    int n90 = (n * n + 3 * (n % 2)) / 4;
    int n180 = (n * n + (n % 2)) / 2;
    int n270 = (n * n + 3 * (n % 2)) / 4;

    // possible ways for configurations (color ^ numbers)
    int ans0 = A_pow_B(2, n0);
    int ans90 = A_pow_B(2, n90);
    int ans180 = A_pow_B(2, n180);
    int ans270 = A_pow_B(2, n270);

    // Burnside lemma says object = (sum of way of symmetical configurations) / symmetrics
    // so ans = (ans0 + ans90 + ans180 + ans270) / 4
    int down = A_pow_B(4, M-2);
    int ans = (ans0%M + ans90%M + ans180%M + ans270%M)%M;
    ans = (ans%M * down%M)%M;
    cout << ans << endl;

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