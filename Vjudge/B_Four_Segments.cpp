#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    vector<int>a(4);
    for(int i=0;i<4;i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    cout << 1ll * a[0] * a[2] << endl;

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