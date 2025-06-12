#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, x; cin >> n >> x;
    vector<int> a(n+2, 0), b(n+2, 0);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    vector<int> mx = a;
    for(int i=n;i>=1;i--) mx[i] = max(mx[i], mx[i+1]);
    vector<int> ppar(n+2, 0), spar(n+2, 0);
    int par = 0;
    for(int i=1;i<=n;i++){
        if(x - par >= b[i] and x - par - 1 >= mx[i+1]) par++;
        ppar[i] = par;
    }
    
    int y = x - par;
    for(int i=n;i>=1;i--){
        if(y + 1 <= x and y + 1 >= b[i]){
            y = y + 1;
            spar[i] = 1 + spar[i+1];
        } else {
            spar[i] = spar[i+1];
        }
    }

    // for(int i=1;i<=n;i++) cout << ppar[i] << " "; cout << endl;
    // for(int i=1;i<=n;i++) cout << spar[i] << " "; cout << endl;

    for(int i=1;i<=n;i++){
        if(ppar[i] > 0 and ppar[i-1] >= par - spar[i+1] - 1){
            if(x - max(0ll, par - spar[i+1] - 1) >= b[i]) cout << '1';
            else cout << '0';
        } else {
            cout << '0';
        }
    } cout << endl;

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