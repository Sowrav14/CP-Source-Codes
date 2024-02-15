#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n+5, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    stack<pair<int,int>>st;
    vector<int>res(n+5, 0);
    st.push({0, 0});

    for(int i=1;i<=n;i++){
        while(!st.empty()){
            int val = st.top().first;
            int idx = st.top().second;
            if(val <= v[i]){
                res[i] = idx;
                break;
            }
            st.pop();
        }
        st.push({v[i], i});
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += res[i] - i;
    }
    cout << -ans << endl;

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