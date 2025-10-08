#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    int m; cin >> m;
    string a, b; cin >> a >> b;
    stack<char> st;
    for(int i=0;i<m;i++){
        if(b[i] == 'D'){
            s += a[i];
        } else {
            st.push(a[i]);
        }
    }
    string p = "";
    while(!st.empty()){
        p += st.top();
        st.pop();
    }
    p += s;
    cout << p << endl;

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