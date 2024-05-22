#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = (n-2) * (n-3); ans /= 2;

    map<pair<int,pair<int,int>>, int>m;
    map<int, vector<pair<int,int>>>m1, m2, m3;
    for(int i=0;i<n-2;i++){
        m[{v[i], {v[i+1], v[i+2]}}]++;
        m1[v[i]].push_back({v[i+1], v[i+2]});
        m2[v[i+1]].push_back({v[i], v[i+2]});
        m1[v[i+2]].push_back({v[i], v[i+1]});
    }
    // cout << ans << endl;
    for(auto i : m){
        ans -= (i.second-1);
    }

    // cout << ans << endl;

    for(auto i : m1){
        vector<pair<int,int>>cur = i.second;
        map<int,vector<int>>temp1, temp2;
        for(auto it : cur){
            temp1[it.first].push_back(it.second);
        }
    }

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