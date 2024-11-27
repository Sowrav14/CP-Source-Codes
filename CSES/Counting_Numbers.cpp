#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
int dp[20];

int recur(string s, int i){
    if(i < 0) return 0;

    int x = s[s.size()-i-1] - '0';
    int ans = (x - 1) * dp[i];
    ans += recur(s, i-1);
    return ans;
}

void generate(){
    dp[0] = 1;
    for(int i=1;i<=18;i++){
        dp[i] = 9 * dp[i-1];
    }
}

void solve(){

    int a, b; cin >> a >> b;
    string na = to_string(a);
    string nb = to_string(b);
    generate();
    cout << dp[0] + dp[1] + dp[2] + recur(nb, nb.size()-1) << endl;

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