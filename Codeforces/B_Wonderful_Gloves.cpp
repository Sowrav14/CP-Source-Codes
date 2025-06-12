#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> L(n), R(n);
    for(int i=0;i<n;i++){
        cin >> L[i];
    }
    for(int i=0;i<n;i++){
        cin >> R[i];
    }

    vector<int> mn(n);
    int ans = 0;
    for(int i=0;i<n;i++){
        int x = max(L[i], R[i]);
        int y = min(L[i], R[i]);
        ans += x;
        mn.push_back(y);
    }
    sort(mn.rbegin(), mn.rend());
    for(int i=0;i<k-1;i++){
        ans += mn[i];
    }
    ans++;
    cout << ans << endl;

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