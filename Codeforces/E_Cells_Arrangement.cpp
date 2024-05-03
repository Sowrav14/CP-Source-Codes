#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;

    vector<pair<int,int>>ans;
    ans.push_back({n,n});
    ans.push_back({n-1, n});

    int i = 1;
    while(ans.size() != n){
        ans.push_back({i, i});
        i++;
    }

    for(auto i : ans){
        cout << i.first << " " << i.second << endl; 
    } cout << endl;

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