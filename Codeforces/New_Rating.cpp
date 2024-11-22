#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


int newRating(int a, int b){
    if(a < b) return a + 1;
    if(a == b) return a;
    return a  - 1;
}

void solve(){

    int n; cin >> n;
    vector<int>a(n+1, 0), dp0(n+1, 0), dp1(n+1, 0), dp2(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];

    dp0[0] = 0;
    dp1[0] = dp2[0] = -n * 4;

    for(int i=1;i<=n;i++){
        dp0[i] = newRating(dp0[i-1], a[i]);

        dp1[i] = max(dp1[i-1], dp0[i-1]);

        dp2[i] = max(dp1[i], newRating(dp2[i-1], a[i]));
    }
    cout << dp2[n] << endl;
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