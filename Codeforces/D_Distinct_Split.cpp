#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

void solve(){

    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> oc(n, vector<int>(26, 0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            oc[i][j] = (i > 0 ? oc[i-1][j] : 0);
        }
        oc[i][s[i] - 'a']++;
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        int res = 0;
        
        for(int j=0;j<26;j++){
            if(oc[i][j] > 0){
                res++;
            }
            if(oc[n-1][j] - oc[i][j] > 0){
                res++;
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;


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