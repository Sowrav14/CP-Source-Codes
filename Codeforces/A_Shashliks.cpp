#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int get(int n, int a, int b, int x, int y){
    int ans = 0;
    int rem = n;
    if(rem >= a){
        int t = ceil((n - a + 1) / (1.0 * x));
        rem = n - t * x;
        ans += t;
    }
    if(rem >= b){
        ans += ceil((rem - b + 1) / (1.0 * y));
    }
    return ans;
}


void solve(){

    int n, a, b, x, y; cin >> n >> a >> b >> x >> y;
    int ans = max(get(n, a, b, x, y), get(n, b, a, y, x));
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