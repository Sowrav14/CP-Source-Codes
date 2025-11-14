#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      string s; cin >> s;
      a[i] = stoi(s, 0, 2);
    }
    int ans = k;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        int x = a[i] ^ a[j];
        ans = min(ans, (int) __builtin_popcountll(x));
      }
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