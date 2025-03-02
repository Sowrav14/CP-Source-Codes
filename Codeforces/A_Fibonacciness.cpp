#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
int a, b, c, d, e;
int fib(){
    int cnt = 0;
    if(c == a+b) cnt++;
    if(d == b + c) cnt++;
    if(e == c + d) cnt++;
    return cnt; 
}

void solve(){

    cin >> a >> b >> d >> e;
    int ans = 0;
    for(int i=-1000;i<=1000;i++){
        c = i;
        ans = max(ans, fib());
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