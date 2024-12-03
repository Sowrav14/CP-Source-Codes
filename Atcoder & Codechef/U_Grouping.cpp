#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 16;
const int M = 1e9 + 7;
const int inf = 1e12;


int n;
int a[N][N];
int score[1<<N];        // what will be the score if we consider some rabbit in a group
int dp[1<<N];

// in mask 1 means not yet grouped.
int group(int mask){
    int rabit = __builtin_popcount(mask);
    if(rabit == 0) return 0;    // no rabbit left for grouping...
    if(dp[mask] != -1) return dp[mask];
    // generate submask of rabit and assume they form new group...
    int ans = -inf;
    for(int subMask=mask;subMask;subMask=(subMask - 1) & mask){ // runs in 3^n
        ans = max(ans, score[subMask] + group(mask ^ subMask));
    }
    return dp[mask] = ans;
}

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];

    // pre-process score for every mask
    for(int mask=0; mask < (1<<n); mask++){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask & (1 << i)) and (mask & (1 << j))){
                    score[mask] += a[i][j];
                }
            }
        }
    }
    // for(int mask=0; mask < (1<<n); mask++) cout << score[mask] << " "; cout << endl;
    memset(dp, -1, sizeof(dp));
    cout << group((1<<n)-1) << endl;

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