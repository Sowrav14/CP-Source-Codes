#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);

    vector<int> ans;

    int prev = -1;
    for(int i=0;i<n;i++){
        if(prev == -1){
            int x = *s.begin();
            ans.push_back(x);
            s.erase(x);
            prev = x;
        } else {
            int x = prev + k;
            if(x <= n and s.find(x) != s.end()){
                ans.push_back(x);
                s.erase(x);
                prev = x;
            } else {
                int x = *s.begin();
                ans.push_back(x);
                s.erase(x);
                prev = x;
            }
        }
    }
    // cout << ans.size() << endl;
    for(auto i : ans) cout << i << " "; cout << endl;
    // for(int i=0;i<n;i++) cout << ans[i] < " "; cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}