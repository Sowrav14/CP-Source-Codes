#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '1') cnt++;
        else {
            if(cnt >= k){
                cout << "NO\n";
                return;
            }
            cnt = 0;
        }
    }
    if(cnt >= k){
        cout << "NO\n";
        return;
    }

    vector<int> ans(n);
    int it = 1;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            ans[i] = it;
            it++;
        }
    }

    for(int i=0;i<n;i++){
        if(s[i] == '0') ans[i] = it++;
    }

    cout << "YES\n";
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";

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