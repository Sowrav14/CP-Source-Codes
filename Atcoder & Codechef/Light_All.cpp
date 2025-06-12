#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    vector<int> vis(n+1, 0);
    if(s[0] == '1') {
        vis[0] = vis[1] = 1;
    }
    for(int i=1;i<n;i++){
        if(s[i] == '1'){
            if(vis[i-1] != 1){
                vis[i-1] = vis[i] = 1;
            } else {
                vis[i] = vis[i+1] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;

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