#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, k;
string s;

int check(int mx){
    int i = 0;
    int cnt = 0;
    while(i < n){
        int j;
        int lz = 0, lo = 0, prev = 0;
        for(j=i;j<n;j++){
            int cur;
            if(s[j] == '1'){
                cur = max(prev + 1, lo + 1);
                lo = cur;
            } else {
                if(j == i) cur = 1;
                else if(s[j-1] == '0') cur = prev + 1;
                else cur = lz + 1;

                lz = cur;
            }
            if(cur >= mx) {
                i = j + 1;
                cnt += 1;
                break;
            }
            prev = cur;
        }
        // cout << j << endl;
        if(j == n) break;
    }
    return cnt;
}


void solve(){

    cin >> n >> k;
    cin >> s;
    // cout << check(4) << endl;
    int l = 1, r = n;
    int ans = 1;
    while(l <= r){
        int m = (l + r) / 2;
        int x = check(m);
        if(x >= k){
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
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