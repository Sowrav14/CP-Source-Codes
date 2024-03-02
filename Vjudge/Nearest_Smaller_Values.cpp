#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    stack<pair<int,int>>st;
    st.push({0, 0});
    for(int i=1;i<=n;i++){
        while(!st.empty()){
            if(st.top().first < v[i]){
                cout << st.top().second << " ";
                break;
            }
            st.pop();
        }
        st.push({v[i], i});
    }

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