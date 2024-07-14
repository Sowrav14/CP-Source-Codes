#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, k;
vector<int>v;
int boro_ta, choto_ta;
// int dp[710][710][710];
map< pair<int, pair<int,int> > , int> ddp;

int recur(int i, int boro_count, int choto_count){
    if(i == n+1){
        if(boro_count == 0 and choto_count == 0) return 0;
        else return INT_MAX;
    }
    if(boro_count < 0) return INT_MAX;
    if(choto_count < 0) return INT_MAX;
    // if(dp[i][boro_count][choto_count] != -1) return dp[i][boro_count][choto_count];
    pair<int, pair<int,int>> x = {i, {boro_count, choto_count}};
    if(ddp[x]) return ddp[x];

    int ans = INT_MAX;
    if(i+boro_ta-1 <= n) ans = min(ans, abs(v[i+boro_ta-1] - v[i]) + recur(i+boro_ta, boro_count-1, choto_count));
    if(i+choto_ta-1 <= n) ans = min(ans, abs(v[i+choto_ta-1] - v[i]) + recur(i+choto_ta, boro_count, choto_count-1));
    // return dp[i][boro_count][choto_count] = ans;
    return ddp[x] = ans;
}

void solve(){
    // memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    v.resize(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin()+1, v.end());
    int div = n / k;
    int rem = n % k;
    int boro_count = rem;
    int choto_count = k - rem; 
    boro_ta = div + 1;
    choto_ta = div;
    cout << recur(1, boro_count, choto_count) << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}