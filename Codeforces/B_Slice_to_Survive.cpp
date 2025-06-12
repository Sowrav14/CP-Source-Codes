#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m, a, b; cin >> n >> m >> a >> b;

    auto get = [&](int x, int y) -> int {
        int ret = 0;
        while(x > 1){
            ret++;
            x = (x + 1) / 2;
        }
        while(y > 1){
            ret++;
            y = (y + 1) / 2;
        }
        return ret;
    };

    int ans = n + m;
    ans = min(ans, get(a, m));
    ans = min(ans, get(n, b));
    ans = min(ans, get(n - a + 1, m));
    ans = min(ans, get(n, m - b + 1));

    cout << 1ll + ans << endl;

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