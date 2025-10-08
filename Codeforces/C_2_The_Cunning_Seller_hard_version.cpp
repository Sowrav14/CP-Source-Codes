#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


vector<int> pows;
vector<int> c;
void generate(){
    long long p = 1;
    for(int x=0;p<=1e10;x++,p*=3){
        pows.push_back(p);
        if(x == 0) c.push_back(3);
        else c.push_back(p * 3 + x * (p / 3));
    }
}

void solve(){

    int n, k; cin >> n >> k;
    // for(int i=0;i<pows.size();i++) cout << c[i] << " "; cout << endl;
    int ans = 0;
    int tot = 0;
    vector<int> deals(pows.size(), 0);
    for(int i=pows.size()-1;i>=0;i--){
        int res = n / pows[i];
        n -= res * pows[i];
        ans += res * c[i];
        tot += res;
        deals[i] = res;
    }

    if(tot > k){
        cout << -1 << endl;
        return;
    }
    k -= tot;

    // cout << k << " " << tot << " " << ans << endl;
    for(int i=deals.size()-1;i>=1;i--){
        if(deals[i] == 0) continue;
        int x = deals[i];
        int mxred = min(x * 2, k);
        int red = mxred / 2;
        ans -= c[i] * red;
        ans += 3 * red * c[i-1];
        deals[i-1] += 3 * red;
        k -= red * 2;

        // cout << i << " -- " << x << " " << ans << endl;
        // while(k >= 2 and x > 0){
        //     k -= 2;
        //     x -= 1;
        //     ans -= c[i];
        //     ans += 3 * c[i-1];
        //     deals[i-1] += 3;
        // }
        // cout << ans << endl;
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    generate();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}