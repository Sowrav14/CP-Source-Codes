#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    string s; cin >> s;
    vector<int>v(10, 0);
    for(int i=1;i<=9;i++){
        int x; cin >> x;
        v[i] = x;
    }
    int pos = n;
    for(int i=0;i<n;i++){
        int cur = s[i] - '0';
        if(v[cur] > cur){
            pos = i;
            break;
        }
    }
    if(pos == n){
        cout << s << endl;
        return;
    }
    vector<int> m(10, 0);
    for(int j=1;j<=9;j++) m[j] = j;

    int i = pos;
    // cout << pos << endl;
    while(i < n){
        int cur = s[i] - '0';
        if(v[cur] >= cur){
            m[cur] = v[cur];
        } else{
            break;
        }
        i++;
    }

    // for(int i=1;i<=9;i++) cout << m[i] << " "; cout << endl;
    for(int i=0;i<n;i++){
        int cur = s[i] - '0';
        s[i] = m[cur] + '0';
    }
    cout << s << endl;
 

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