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
    for(int i=0;i<n;i++) cin >> a[i];

    int prev = 0, cur = 0, cnt = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(a[i] == -1){
            cnt++;
        } else {
            int temp = cnt * 1e9 + cur;
            ans = max(ans, temp);
            if(a[i] >= prev){
                cur += a[i] * (cnt + 1);
            } else {
                cur = a[i] * (cnt + 1);
            }
            prev = a[i];
            cnt = 0;
        }
        ans = max(ans, cur);
    }
    cur += cnt * 1e9;
    ans = max(ans, cur);
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