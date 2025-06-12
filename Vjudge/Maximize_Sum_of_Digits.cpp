#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int dp[20][2][200];
struct Digitdp{
    int n;
    vector<int>num;
    vector<int>ret;

    Digitdp(int a){
        n = a;
        while(a > 0){
            num.push_back(a % 10);
            a /= 10;
        }
        reverse(num.begin(), num.end());
    }

    int recur(int i, bool f, int dsum){
        if(i == num.size()){;
            return dsum;
        }
        if(dp[i][f][dsum] != -1) return dp[i][f][dsum];
        int ans = 0;
        int limit;
        if(f) limit = 9;
        else limit = num[i];

        for(int it=0;it<=limit;it++){
            bool nf = f;
            if(it < num[i]) nf = 1;
            ans = max(ans, recur(i+1, nf, (dsum + it)));
        }
        return dp[i][f][dsum] = ans;
    }
    void extractor(int i, int f, int dsum, int sum, int mxsum){
        if(i == num.size()) {
            ret.push_back(sum);
            return;
        }

        int limit = 0;
        if(f) limit = 9;
        else limit = num[i];

        for(int it=0;it<=limit;it++){
            bool nf = f;
            if(it < num[i]) nf = 1;
            if(recur(i+1, nf, dsum+it) == mxsum) {
                extractor(i+1, nf, dsum+it, sum*10+it, mxsum);
            }
        }
    }

    int query(){
        memset(dp, -1, sizeof(dp));
        int mxsum = recur(0, 0, 0);
        extractor(0, 0, 0, 0, mxsum);
        sort(ret.begin(), ret.end());
        return ret.back();
    }
};


void solve(){

    int n; cin >> n;
    Digitdp digitdp(n);
    cout << digitdp.query() << endl;

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