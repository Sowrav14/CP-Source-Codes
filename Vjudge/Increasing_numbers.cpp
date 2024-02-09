#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>lis;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        int it = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
        if(it == lis.size()){
            lis.push_back(x);
        } else{
            lis[it] = x;
        }
    }
    int k; cin >> k;
    if(k > lis.size()){
        cout << -1 << endl;
        return;
    }
    cout << lis[k-1] << endl;

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