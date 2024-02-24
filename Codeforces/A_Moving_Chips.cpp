#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int fst,lst;
    for(int i=0;i<n;i++){
        if(v[i] == 1){
            fst = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(v[i] == 1){
            lst = i;
            break;
        }
    }
    int ans = 0;
    for(int i=fst;i<=lst;i++){
        if(v[i] == 0){
            ans++;
        }
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