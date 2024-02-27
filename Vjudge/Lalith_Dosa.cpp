#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    vector<int>lis;
    for(int i=0;i<n;i++){
        if(v[i] - i <= 0) continue;
        int it = upper_bound(lis.begin(), lis.end(), (v[i]-i)) - lis.begin();
        if(it == lis.size()){
            lis.push_back(v[i]-i);
        } else {
            lis[it] = v[i] - i;
        }
    }

    cout << n - lis.size() << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}