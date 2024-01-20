#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    map<int,int>m;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        m[x]++;
    }

    int prev = 0;
    int ans = 0;
    for(auto i : m){
        int x = i.second;
        int self = (x * (x-1) * (x-2)) / 6;
        int pre = (x * (x-1) * prev) / 2;

        ans += self + pre;
        prev += x;
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}