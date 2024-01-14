#include<bits/stdc++.h>
using namespace std;
//#define int long long int


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int>div;
    int sz = n;
    for(int i=1;i*i<=sz;i++){
        if(sz % i == 0){
            div.push_back(i);

            int snd = sz / i;
            if(snd != i) div.push_back(snd);
        }
    }
    // for(auto i : div) cout << i << " "; cout << endl;
    int ans = 0;
    for(auto k : div){
        int g = 0;
        for(int i=0;i+k<n;i++){
            g = __gcd(g, abs(v[i+k] - v[i]));
        }
        if(g != 1) ans++;
    }
    cout << ans << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}