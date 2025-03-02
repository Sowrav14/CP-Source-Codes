#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n), oc(n, 0);
    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(), v.end());
    int mex = 0;
    for(int i=0;i<n;i++){
        oc[v[i]]++;
        if(v[i] == mex){
            mex++;
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(oc[v[i]] == 1){
            ans.push_back(v[i]);
        }
    }
    
    if(ans.size() > 1){
        mex = min(mex, ans[1]);
    }

    cout << mex << endl;

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