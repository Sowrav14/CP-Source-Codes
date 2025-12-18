#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 

const int N = 2e5 + 10;
int a[N];
int lt[N], rt[N], pos[N];
int dp[N];


void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pos[a[i]] = i;
        lt[i] = rt[i] = 0;
        dp[i] = 0;
    }

    vector<int> st;
    for(int i=1;i<=n;i++){
        int last = 0;
        while(!st.empty() && a[st.back()] < a[i]){
            last = st.back();
            st.pop_back();
        }
        if(!st.empty()) rt[st.back()] = i;
        if(last) lt[i] = last;
        st.push_back(i);
    }
    for(int i=1;i<=n;i++) cout << lt[i] << " " << rt[i] << endl;
    for(int i = 1; i <= n; i++){
        int u = pos[i];
        int best = 0;
        if(lt[u]) best = max(best, llabs(u - lt[u]) + dp[lt[u]]);
        if(rt[u]) best = max(best, llabs(u - rt[u]) + dp[rt[u]]);
        dp[u] = best;
    }

    cout << dp[pos[n]] << endl;
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
