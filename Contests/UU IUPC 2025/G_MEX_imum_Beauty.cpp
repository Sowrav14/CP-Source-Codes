#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct node {
    int val, cnt, sum;
    node(int v, int c, int s) : val(v), cnt(c), sum(s) {}
    node() : val(0), cnt(0), sum(0) {}
};

void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    stack<node> st;
    st.push(node(n+2, -1, -1));
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top().val <= a[i]) st.pop();

        node curr(a[i], 1, i);
        if(!st.empty() and st.top().val == a[i] + 1){
            curr.cnt += st.top().cnt;
            curr.sum += st.top().sum;
        }
        st.push(curr);
        if(a[i] == 0){
            ans += curr.cnt * n - curr.sum;
        }
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