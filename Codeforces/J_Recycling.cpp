#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    stack<pair<int,int>>st;
    vector<int>pref(n+1), suf(n+1);
    for(int i=1;i<=n;i++){
        while(!st.empty() and st.top().first >= v[i]){
            st.pop();
        }
        if(st.empty()){
            pref[i] = 0;
        }else{
            pref[i] = st.top().second;
        }

        st.push({v[i], i});
    }
    stack<pair<int,int>>s;
    for(int i=n;i>=1;i--){
        while(!s.empty() and s.top().first >= v[i]){
            s.pop();
        }
        if(s.empty()){
            suf[i] = n+1;
        }else{
            suf[i] = s.top().second;
        }

        s.push({v[i],i});
    }

    // for(int i=1;i<=n;i++) cout << pref[i] << " "; cout  << endl;
    // for(int i=1;i<=n;i++) cout << suf[i] << " "; cout  << endl;

    int ans = 0;
    for(int i=1;i<=n;i++){
        int res = v[i] * (suf[i] - pref[i] - 1);
        ans = max(ans, res);
    }
    for(int i=1;i<=n;i++){
        int res = v[i] * (suf[i] - pref[i] - 1);
        if(res == ans){
            cout << pref[i]+1 << " " << suf[i]-1 << " " << ans << endl;
            return;
        }
    }
    // cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}