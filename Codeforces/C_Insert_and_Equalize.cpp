#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());

    int x = 0;
    for(int i=0;i<n-1;i++){
        x = __gcd(x, abs(a[i] - a[i+1]));
    }
    if(x == 0){
        cout << 1 << endl;
        return;
    }
    // cout << x << endl;
    int mx = a.back();
    int ans = 0;
    for(int i=0;i<n-1;i++){
        ans += (mx - a[i]) / x;
    }
    for(int i=1;i<n;i++){
        int temp = mx - x * i;
        if(mp[temp] == 0){
            ans += i;
            cout << ans << endl;
            return;
        }
    }

    cout << ans + n << endl;

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