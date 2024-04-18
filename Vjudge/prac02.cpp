#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


void solve(){

    int n; cin >> n;
    int mx = 0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int freq[mx+10] = {0};
    int ans = 0;
    for(int i=0;i<n;i++){
        int x = a[i];
        int y = ceil(x / 2.0);
        for(int j=1;j<y;j++){
            ans += (freq[j] * freq[x - j]);
        }

        if(x%2 == 0){
            ans += (freq[y] * (freq[y]-1)) / 2;
        }

        freq[x]++;
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