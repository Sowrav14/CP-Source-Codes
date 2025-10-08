#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    map<int,int> m;
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        m[x]++;
    }
    int mx = 0, p = 1;
    for(auto i : m){
        if(i.second > mx){
            mx = i.second;
            p = i.first;
        } else if(i.second == mx){
            p = min(p, i.first);
        }
    }
    // cout << mx << " " << p << endl;
    if(p == 1){
        cout << n - mx << endl;
    } else {
        cout << n - mx + 1 << endl;
    }

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