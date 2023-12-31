#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    vector<int>odd(n+1, 0), sum(n+1, 0);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        sum[i] = sum[i-1] + x;
        if(x%2) odd[i] = odd[i-1] + 1;
        else odd[i] = odd[i-1];
    }
    // for(int i=1;i<=n;i++) cout << odd[i] << " "; cout << endl;
    cout << sum[1] << " ";
    for(int i=2;i<=n;i++){
        int odcnt = odd[i];
        int x = odcnt / 3;
        if(odcnt % 3 == 1) x++;
        cout << sum[i] - x << " ";
    } cout << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}