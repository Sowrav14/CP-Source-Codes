#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n+1), e(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) cin >> e[i];
    stack<pair<int,int>> st;
    vector<int> le(n+1, n+1);
    st.push({0, n+1});
    for(int i=n;i>=1;i--){
        while(!st.empty() and st.top().first >= v[i]) st.pop();
        le[i] = st.top().second;
        st.push({v[i], i});
    }    

    // for(int i=1;i<=n;i++) cout << le[i] << " "; cout << endl;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(le[i] == n + 1) {
            ans.push_back(i);
        } else {
            if(e[i] > e[le[i]]) ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " "; cout << endl;

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