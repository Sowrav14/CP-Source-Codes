#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m, x, y, d; cin >> n >> m >> x >> y >> d;
    int ans = (n + m - 2);

    int left = max(1ll, y - d);
    int right = min(m, y + d);
    int down = max(1ll, x + d);
    int up = min(n, x - d);
    // cout << up << " " << down << " " << left << " " << right << endl;
    if(left != 1 and down != n){
        cout << ans << endl;
    }
    else if(right != m and up != 1){
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
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