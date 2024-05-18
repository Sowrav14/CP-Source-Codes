#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int pillow(int b, int h){
    int ret = h * (h + 1);
    ret /= 2;

    if(b > h){
        ret += (b - h);
    } else{
        int x = h - b;
        x = x * (x + 1);
        x /= 2;
        ret -= x;
    }

    return ret;
}


void solve(){

    int n,m,k; cin >> n >> m >> k;
    
    int l = 1, r = m;
    int ans = 1;
    while(l <= r){
        int mid = (l + r) / 2;

        int left = pillow(k-1, mid-1);
        int right = pillow(n-k, mid-1);
        int total = left + mid + right;

        if(total <= m){
            ans = mid;
            l = mid + 1;
        } else{
            r = mid - 1;
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