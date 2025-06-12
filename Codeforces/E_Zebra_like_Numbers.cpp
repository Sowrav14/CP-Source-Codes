#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


int dp[32][100][2][2];
vector<int> z;  // zebroid numbers
struct Digitdp{
    int n, k;
    vector<int>num;

    // convert to zebroid form
    Digitdp(int a, int k) : n(a), k(k){
        for(auto i : z){
            int cnt = 0;
            while(a >= i){
                cnt++;
                a -= i;
            }
            num.push_back(cnt);
        }
    }

    int recur(int i, int sum, bool f, bool four){
        if(i == num.size()){
            if(sum == k){
                return 1;
            } else {
                return 0;
            }
        }
        if(dp[i][sum][f][four] != -1) return dp[i][sum][f][four];
        int ans = 0;
        int limit;
        if(four){ // already seen a four
            limit = 0;
        } else if(f){ // it is already less
            limit = 4;
        } else {    // should be less or equal num[i]
            limit = num[i];
        }

        for(int it=0;it<=limit;it++){
            bool nf = f, nfour = four;
            if(it < num[i]) nf = 1; // it becoming less
            if(it == 4) nfour = 1; // got a four
            ans += recur(i + 1, sum + it, nf, nfour);
        }
        return dp[i][sum][f][four] = ans;
    }

    int query(){
        memset(dp, -1, sizeof(dp));
        return recur(0, 0, 0, 0);
    }
};


void zebroids(){
    int i = 1;
    while(i<=1e18){
        z.push_back(i);
        i = 4 * i + 1;
    }
    reverse(z.begin(), z.end());
}


void solve(){

    int l, r, k; cin >> l >> r >> k;
    Digitdp dp1(--l, k), dp2(r, k);
    // cout << r << " " << dp2.query() << endl;
    cout << dp2.query() - dp1.query() << endl;

}


signed main(){
    Fast_IO()
    zebroids();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}