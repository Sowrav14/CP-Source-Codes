#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,q; cin >> n >> q;
    vector<int>a(n+1, 0), pref(n+1, 0);

    for(int i=1;i<=n;i++) cin >> a[i];

    stack<pair<int,int>>st;
    st.push({-1, 0});

    for(int i=1;i<=n;i++){
        while(!st.empty()){
            if(a[i] != st.top().first){
                pref[i] = st.top().second;
                break;
            }
            st.pop();
        }
 
        st.push({a[i], i});
    }

    while(q--){
        int l,r,x; cin >> l >> r >> x;
        if(a[r] != x){
            cout << r << endl;
            continue;
        }

        int nn = pref[r];
        if(nn >= l){
            cout << nn << endl;
            continue;
        }
        cout << -1 << endl;
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