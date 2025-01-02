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
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    int x = v[0];
    sort(v.begin(), v.end());

    int prev = 0, next = 1000001;
    for(int i=0;i<n;i++){
        if(v[i] == x) break;
        prev = v[i];
    }

    for(int i=n-1;i>=0;i--){
        if(v[i] == x) break;
        next = v[i];
    }

    int ans = 1;
    if(prev == 0){
        ans += x - 1;
    } else {
        ans += (x - prev) / 2;
    }

    if(next == 1000001){
        ans += (1000000 - x);
    } else {
        ans += (next - x) / 2;
    }

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