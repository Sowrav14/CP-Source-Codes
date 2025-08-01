#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];


    auto check = [&](int m) -> pair<int,int> {
        vector<int> t(n+1, 0);
        for(int i=0;i<n;i++) t[i] = (a[i] >= m) ? 1 : -1;
        for(int i=n-1;i>=0;i--) t[i] += t[i+1];
        pair<int,int> res = {-1, -1};
        int cur = 0;
        for(int i=k-1;i<n;i++){
            if(t[cur] < t[i-k+1]) cur = i - k + 1;
            if(t[cur] - t[i+1] >= 0){
                res = {cur, i};
                break;
            }
        }
        return res;
    };


    int ans = 0;
    int ansL = -1, ansR = -1;
    int l = 1, r = n;
    while(l <= r){
        int m = (l + r) / 2;
        pair<int,int> res = check(m);
        if(res.first != -1){
            ans = m;
            ansL = res.first, ansR = res.second;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << " " << ansL + 1 << " " << ansR + 1 << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}