#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin >> a[i];
    a[0] = inf, a[n+1] = inf;
    stack<int> st;
    vector<int> left(n+1), right(n+1);
    st.push(0);
    for(int i=1;i<=n;i++){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        left[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    st.push(n+1);
    for(int i=n;i>=1;i--){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        right[i] = st.empty() ? n+1 : st.top();
        st.push(i);
    }

    // for(int i=1;i<=n;i++) cout << left[i] << " "; cout << endl;
    // for(int i=1;i<=n;i++) cout << right[i] << " "; cout << endl;
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, a[i] * (right[i] - left[i] - 1));
    }
    cout << ans << endl;

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