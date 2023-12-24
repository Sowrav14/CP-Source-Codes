#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){

    int n; cin >> n;
    vector<int>v(n);
    int ans = 0;
    int flag = 0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v[i] = x;
        if(v[i] < 0) ans++;
        if(v[i] == 0) flag = 1;
    }
    if(ans % 2 == 1 or flag == 1){
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << 1 << " " << 0 << endl;

}


signed main(){
    int t; cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}