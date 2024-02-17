#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    string s; cin >> s;
    int n = s.size();
    stack<int>st;
    vector<int>d(n, -1), dp(n, -1);
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            st.push(i);
        } else{
            if(st.empty()){
                d[i] = -1;
            } else{
                d[i] = st.top();
                st.pop();
            }
        }
        if(d[i] != -1){
            dp[i] = i - d[i] + 1;
        }
    }

    for(int i=1;i<n;i++){
        int x = d[i];
        if(d[i] == 0) continue;
        if(d[i] == -1) continue;

        int xx = d[i] - 1;
        if(xx >= 0 and s[xx] == ')'){
            if(dp[xx] != -1){
                dp[i] += dp[xx];
            }
        }
    }

    // for(int i=0;i<n;i++) cout << d[i] << " "; cout << endl;
    // for(int i=0;i<n;i++) cout << dp[i] << " "; cout << endl;

    int mx = 0;
    for(int i=0;i<n;i++){
        mx = max(mx, dp[i]);
    }
    if(mx == 0){
        cout << 0 << " " << 1 << endl;
    } else{
        cout << mx << " " << count(dp.begin(), dp.end(), mx) << endl;
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