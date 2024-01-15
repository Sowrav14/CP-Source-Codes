#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n,a,m,mul; cin >> n >> a >> m >> mul;
    vector<int>v(n);
    int cur = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        int x = v[i] - cur;
        cur = v[i];
        int one = x * m;
        int two = mul;
        ans += min(one, two);
    }

    if(ans < a){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}