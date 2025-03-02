#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    vector<vector<int>> g;
    bool flag = true;
    vector<int>ind(n+10, 0);
    for(int i=0;i<n;i++){
        vector<int>r;
        for(int j=0;j<m;j++){
            int x; cin >> x;
            r.push_back(x);
        }
        sort(r.begin(), r.end());
        for(int j=0;j<m;j++){
            if(j != 0 and r[j] - r[j-1] != n) flag = false;
            if(r[j] < n){
                ind[r[j]] = i + 1; 
            }
        }
        g.push_back(r);
    }

    if(!flag){
        cout << -1 << endl;
        return;
    }
    // ind[i] = x. xth cow have i
    vector<int>ans(n+1);
    for(int i=0;i<n;i++){
        cout << ind[i] << " ";
    }
    cout << endl;

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