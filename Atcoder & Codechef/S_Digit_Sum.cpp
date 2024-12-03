#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e4 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
int k;
vector<int>nums;
int dp[N][2][100];

int digitdp(int i, int f, int d){
    if(i == n) return d == 0;
    if(dp[i][f][d] != -1) return dp[i][f][d];

    int limit;
    if(f) limit = 9;
    else limit = nums[i];

    int ans = 0;
    for(int it=0;it<=limit;it++){
        ans += digitdp(i+1, (it<nums[i] ? 1 : f), (d + it)%k);
        ans %= M;
    }
    return dp[i][f][d] = ans;
}

void solve(){

    string s; cin >> s;
    n = s.size();
    cin >> k;
    for(int i=0;i<s.size();i++){
        nums.push_back(s[i] - '0');
    }
    memset(dp, -1, sizeof(dp));
    cout << digitdp(0, 0, 0) - 1 << endl;
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