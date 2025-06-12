#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, l; cin >> n >> l;
    vector<int> v(l+1, 0);

    int x = 1;
    v[1] = 1;
    for(int i=2;i<=n;i++){
        int y; cin >> y;
        x = x + y;
        x %= l;
        v[x]++;
    }

    // for(int i=1;i<=l;i++) cout << v[i] << " "; cout << endl;

    if(l%3){
        cout << 0 << endl;
        return;
    }

    int d = l / 3;
    int ans = 0;
    int m = 1 + l / 3;
    // cout << d << " " << m << endl;

    for(int i=1;i<m;i++){
        int a = i;
        int b = (i + d) % l;
        int c = (i + 2 * d) % l;
        // cout << a << " " << b << " " << c << endl;
        // cout << v[a] << " " << v[b] << " " << v[c] << endl;
        ans += 1ll * v[a] * v[b] * v[c];
    }
    cout << ans << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}