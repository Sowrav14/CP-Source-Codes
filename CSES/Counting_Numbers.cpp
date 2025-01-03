#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int dp[20][12][2];

struct Digitdp{
    int n;
    vector<int>num;

    Digitdp(int a){
        n = a;
        while(a > 0){
            num.push_back(a % 10);
            a /= 10;
        }
        reverse(num.begin(), num.end());
    }

    int recur(int i, int prev, int f){
        if(i == num.size()){
            return 1;
        }
        if(dp[i][prev][f] != -1) return dp[i][prev][f];
        int ans = 0;
        int limit;
        if(f) limit = 9;
        else limit = num[i];

        for(int it=0;it<=limit;it++){
            if(it == prev) continue;
            int np = it;
            if(it == 0 and prev == 11) np = 11;
            bool nf = f;
            if(it < num[i]) nf = 1;
            ans += recur(i+1, np, nf);
        }
        return dp[i][prev][f] = ans;
    }

    int query(){
        if(n < 0) return 0;
        memset(dp, -1, sizeof(dp));
        return recur(0, 11, 0);
    }
};


void solve(){

    int a, b; cin >> a >> b;
    Digitdp dp1(a-1), dp2(b);
    cout << dp2.query() - dp1.query() << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << i << ": ";
        solve();
    }
}