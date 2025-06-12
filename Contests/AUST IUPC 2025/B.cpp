#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    vector<int>v(n);
    vector<int>vis(n+1, 0);
    v[n-1] = n;
    vis[n] = 1;
    int l = 1, r = n - 2;
    int L = n - 1, R = 1;
    while(l <= r){
        if(l == r){
            v[r] = R;
            vis[R] = 1;
            break;
        }
        v[l] = L;
        v[r]  = R;
        l++, r--;
        vis[L] = 1;
        vis[R] = 1;
        L--, R++;
    }
    int x = -1;
    for(int i=1;i<=n;i++) if(vis[i] == 0) x = i;
    v[0] = x;

    for(int i=0;i<n;i++) cout << v[i] << " "; cout << "\n";

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