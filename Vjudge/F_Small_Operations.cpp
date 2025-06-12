#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int> divs[N];
int dp[N];
void divisor(){
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divs[j].push_back(i);
        }
    }
}

int recur(int x, int k){
    if(x == 1) return 0;
    if(dp[x] != -1) return dp[x];
    int ret = inf;
    for(auto d : divs[x]){
        if(d > k) break;
        ret = min(ret, 1 + recur(x/d, k));
    }
    return dp[x] = ret;
}

void solve(){

    int x, y, k; cin >> x >> y >> k;
    int g = __gcd(x, y);
    x /= g; y /= g;
    
    dp[1] = 0;
    for(int i=2;i<=max(x, y);i++) dp[i] = (i<=k ? 1 : -1);

    int ans = recur(x, k) + recur(y, k);
    if(ans >= inf) cout << -1 << endl;
    else cout << ans << endl;
}


signed main(){
    Fast_IO()
    divisor();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}