#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;


int n, k;
vector<int>primes;

const int inf = 1e19;

void solve(){

    cin >> n >> k;
    primes.resize(k);
    for(int i=0;i<k;i++) cin >> primes[i];
    int ans = 0;
    for(int i=1;i<(1<<k);i++){
        int sig = -1;
        if(__builtin_popcount(i) % 2 == 1) sig = 1;
        int prod = 1;
        for(int b=0;b<k;b++){
            if(i & (1 << b)){
                float d = log10l(prod) + log10l(primes[b]);
                if(d <= 19.0){
                    prod = prod * primes[b];
                } else {
                    prod = inf;
                    break;
                }
            }
        }
        int res = n / prod; res *= sig;
        ans += res;
    }
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