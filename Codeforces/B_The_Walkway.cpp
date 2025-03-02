#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int m, n, d; cin >> m >> n >> d;
    vector<int> seller;
    seller.push_back(1-d);
    for(int i=0;i<n;i++){
        int x; cin >> x;
        seller.push_back(x);
    }
    seller.push_back(m+1);

    int ans = 2e9;
    vector<int> ansarr;
    for(int i=1;i<=n;i++){
        int p = seller[i] - seller[i-1] - 1;
        int q = seller[i+1] - seller[i] - 1;
        int r = seller[i+1] - seller[i-1] - 1;
        int res = (r / d )- (p / d + q / d);
        if(res < ans){
            ans = res;
            ansarr.clear();
        }
        if(res == ans){
            ansarr.push_back(seller[i]);
        }
    }
    for(int i=1;i<=n+1;i++){
        ans += (seller[i] - seller[i-1] - 1) / d;
    }
    ans += n - 1;
    cout << ans << " " << ansarr.size() << endl;
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