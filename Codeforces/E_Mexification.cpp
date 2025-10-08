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
    for(int i=0;i<n;i++) cin >> a[i];
    
    
    vector<int> freq(n+1, 0);
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    
    int curmex = 0;
    for(int i=0;i<=n;i++) {
        if(freq[i] == 0) {
            curmex = i;
            break;
        }
    }
    
    if(k == 1){
        int ans = 0, cnt = 0;
        for(int i=0;i<curmex;i++){
            if(freq[i] == 1){
                cnt++;
                ans += i;
            }
        }
        ans += (n - cnt) * curmex;
        cout << ans << endl;
        return;
    }

    int cng = -1;
    for(int i=0;i<curmex;i++){
        if(freq[i] > 1){
            cng = i;
            break;
        }
    }    
    // cout << curmex << endl;
    int ans = 0;
    if(cng == -1){
        int res = curmex * (curmex - 1);
        res /= 2;
        int rem = n - curmex;
        // cout << res <<  "-- " << rem << endl;
        if(rem == 1){
            ans = res + curmex;
        } else {
            ans = res + rem * (curmex + (k%2 == 0));
        }
    } else {
        int res = cng * (cng - 1);
        res /= 2;
        int rem = n - cng;
        ans = res + rem * (cng + (k%2));
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