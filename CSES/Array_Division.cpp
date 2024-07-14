#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int a[200010];
int n,k;

bool check(int mx){
    int sum = 0, cnt = 0;
    for(int i=1;i<=n;i++){
        if(a[i] > mx) return false;
        sum += a[i];
        if(sum > mx){
            sum = a[i];
            cnt++;
        }
    }
    return cnt < k;
}

void solve(){

    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    int l = 1, r = 1e18;
    int ans = 1e18;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            r = m - 1;
            ans = m;
        } else{
            l = m + 1;
        }
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}