#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
int sz;
vector<int>do_dp;
int dp[N][2];

int recur(int i, int flag){
    if(flag > 1) return 1e15;
    if(i >= sz - 1) return 0;
    if(dp[i][flag] != -1) return dp[i][flag];
    int ans = 1e15;
    ans = min(ans,  do_dp[i+1] - do_dp[i] + recur(i+2, flag));
    ans = min(ans, recur(i+1, flag + 1));
    return dp[i][flag] = ans;
}


// void temp(){
//     do_dp.push_back(2);
//     do_dp.push_back(7);
//     do_dp.push_back(10);
//     do_dp.push_back(11);
//     do_dp.push_back(15);
//     sz = 5;

//     cout << recur(0, 0) << endl;
// }


void solve(){

    int n,k; cin >> n >> k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    map<int,vector<int>>m;
    for(int i=0;i<n;i++){
        int x = v[i];
        int mod = x % k;
        int div = x / k;
        m[mod].push_back(div);
    }

    int ans = 0;
    int flag = 0;
    for(auto el : m){
        vector<int>vec = el.second;
        if(vec.size() % 2){
            flag++;
            if(flag > 1) {
                cout << -1 << endl;
                return;
            }
            do_dp = vec;
            sz = do_dp.size();
            for(int i=0;i<sz;i++){
                dp[i][0] = dp[i][1] = -1;
            }
            ans += recur(0, 0);
        } else{
            for(int i=0;i<vec.size();i+=2){
                ans += (vec[i+1] - vec[i]);
            }
        }
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}