#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n+2, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }

    int i = ceil(n/2.0), j = ceil((n+1)/2.0);
    map<pair<int,int>, int>m;
    int curand = v[i] & v[j];
    m[{i,j}] = curand;
    i--, j++;
    while(i>0 and j<=n){
        curand = curand & v[j] & v[i];
        m[{i, j}] = curand;
        i--, j++;
    }

    // for(auto i : m){
    //     cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    // }

    vector<int>ans;
    i = 0, j = n + 1;
    int orr = 0;
    while(i<=j){
        orr = orr | v[i] | v[j];
        i++, j--;
        int res = orr;
        if(i <= j){
            res = res & (m[{i, j}]);
        }
        ans.push_back(res);
    }
    while(ans.size() < n){
        ans.push_back(orr);
    }

    reverse(ans.begin(), ans.end());
    for(int i=0;i<n;i++){
        cout << ans[i] << " \n" [i == n-1];
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