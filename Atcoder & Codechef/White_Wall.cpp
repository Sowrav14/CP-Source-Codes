#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s;cin >> s;
    vector<char>v={'B','R','G'};
    vector<char>demo=v;
    int ans=__INT_MAX__;
    while(1){

        int cnt=0;
        for(int i=0;i<n;i++){
            if(v[i%3]!=s[i]) cnt++;
        }
        ans=min(ans,cnt);
        next_permutation(v.begin(),v.end());
        if(v==demo) break;
        
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