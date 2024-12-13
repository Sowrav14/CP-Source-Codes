#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 15;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
vector<int>a;
int dp[1<<N];

int recur(int mask){
    
    // cout << (mask & (1 << 0)) << endl;
    int flag = 1;
    for(int i=0;i<n;i++){
        if((mask & (1 << i)) == 0) flag = 0;
    }
    if(flag == 1) return 0;
    if(dp[mask] != -1) return dp[mask];
    // cout << "HERE" <<endl;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int x = ((mask & (1 << i)) == 0);
                x &= ((mask & (1 << j)) == 0);
                x &= ((mask & (1 << k)) == 0);
                // cout << x << endl;
                if(a[i] + a[j] > a[k] and x){
                    // cout << i << " " << j << " " << k << endl;
                    int nmask = mask;
                    nmask = (nmask | (1 << i));
                    nmask = (nmask | (1 << j));
                    nmask = (nmask | (1 << k));
                    ans = max(ans, 1 + recur(nmask));
                }
            }
        }
    }
    return dp[mask] = ans;
}


void solve(){

    cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    memset(dp, -1, sizeof(dp));
    // cout << "x" << endl;
    cout << recur(0) << endl;
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