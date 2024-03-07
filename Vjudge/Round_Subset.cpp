#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 210;
pair<int,int> a[N];
int n,k;
int dp[210][210][210];

int roundness(int i, int j, int five){
    if(j == k){
        return 0;
    }
    if(i > n){
        return INT_MIN;
    }
    if(dp[i][j][five] != -1) return dp[i][j][five];

    int ans = 0;
    ans = max(ans, roundness(i+1, j, five));
    ans = max(ans, a[i].first + roundness(i+1, j+1, five+a[i].second));
    return dp[i][j][five] = ans;
}


void solve(){

    cin >> n >> k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int tot = 0;
    for(int i=0;i<n;i++){
        map<int,int>m;
        int x = v[i];
        while(x % 2 == 0){
            m[2]++;
            x /= 2;
        }
        while(x % 5 == 0){
            m[5]++;
            x /= 5;
        }
        a[i+1].first = m[2];
        a[i+1].second = m[5];
        tot += m[5];
    }
    for(int i=1;i<=n;i++){
        cout << a[i].first << " " << a[i].second << endl;
    }
    // cout << roundness(1, 0, 0) << endl;

    for(int i=1;i<=n;i++){
        
    }

    

}


signed main(){
    Fast_IO()
    memset(dp, 0, sizeof(dp));
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}