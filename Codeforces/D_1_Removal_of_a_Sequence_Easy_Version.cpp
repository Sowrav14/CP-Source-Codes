#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int inf = 1e12;


int survivors(int m, int x, int y){
    for(int i=0;i<x;i++){
        m -= m / y;
    }
    return m;
}

void solve(){
    int x, y, k; 
    cin >> x >> y >> k;
    if(y == 1){
        cout << -1 << endl;
        return;
    }
    int l = k, r = inf, ans = -1;
    while(l <= r){
        int m = (l + r) / 2;
        int rem = survivors(m, x, y);
        if(rem >= k){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << ans << endl;
}

signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
