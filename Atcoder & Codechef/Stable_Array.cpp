#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    vector<int>ng(n+1, 0);
    stack<pair<int,int>>st;
    st.push({inf, 0});
    for(int i=1;i<=n;i++){
        while(!st.empty() and st.top().first < v[i]){
            st.pop();
        }
        ng[i] = st.top().second;
        st.push({v[i], i});
    }

    // for(int i=1;i<=n;i++) cout << ng[i] << " "; cout << endl;

    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = i - ng[i] - 1;
        // cout << x << endl;
        ans = max(ans, x);
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