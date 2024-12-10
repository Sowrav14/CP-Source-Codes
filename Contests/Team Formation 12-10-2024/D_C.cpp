#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 998244353;
const int inf = 1e12;

map<int,int>m;
int recur(int n){
    if(n <= 4) return n;
    if(m.count(n) != 0) return m[n];
    int ans = 1;
    int x = (n+1) / 2;
    int y = n / 2;
    int xx = recur(x);
    int yy = recur(y);
    ans = (ans%M * xx%M)%M;
    ans = (ans%M * yy%M)%M;
    return m[n] = ans;
}

void solve(){

    int n; cin >> n;
    cout << recur(n) << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}