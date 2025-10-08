#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, q; cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int j=1;j<=n;j++) cin >> b[j];

    vector<int> c(n + 1);
    int sum = 0;
    for(int i=1;i<=n;i++){
        c[i] = min(a[i], b[i]);
        sum += c[i];
    }

    while(q--){
        char ch; cin >> ch;
        int x, y; cin >> x >> y;
        if(ch == 'A'){
            sum -= c[x];
            a[x] = y;
            c[x] = min(a[x], b[x]);
            sum += c[x];
            cout << sum << "\n";
        } else {
            sum -= c[x];
            b[x] = y;
            c[x] = min(a[x], b[x]);
            sum += c[x];
            cout << sum << "\n";
        }
    }

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