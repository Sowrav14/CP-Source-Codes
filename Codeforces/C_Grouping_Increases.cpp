#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int a = INT_MAX, b = INT_MAX;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(a > b) swap(a, b);

        if(v[i] <= a){
            a = v[i];
        } else if(v[i] <= b){
            b = v[i];
        } else{
            a = v[i];
            ans++;
        }
    }

    cout << ans << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}