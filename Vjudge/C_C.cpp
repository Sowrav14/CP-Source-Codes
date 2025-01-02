#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = n;
    int i = 0;
    while(i < n){
        int j = i;
        while(j+1 < n and v[j+1] - v[j] == v[i+1] - v[i]) j++;
        int len = j - i + 1;
        int res = len * (len + 1); res /= 2; res -= len;
        ans += res;
        if(i == j) break;
        i = j;
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