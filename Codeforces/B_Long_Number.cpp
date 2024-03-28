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
        if(pos != n) break;
        if(v[cur] > cur){
            pos = i;
            while(pos < n){
                int c = s[pos] - '0';
                if(v[c] >= c){
                    s[pos] = v[c] + '0';
                } else{
                    break;
                }
                pos++;
            }
            i = pos;
        }
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