#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    string s, t; cin >> s >> t;
    map<char, int> mp;
    for(int i=0;i<t.size();i++) mp[t[i]]++;
    // for(auto [c, x] : mp) cout << c << " " << x << endl;
    for(int i=1;i<s.size();i++){
        if(isupper(s[i])){
            if(mp.count(s[i-1]) == 0){
                // cout << i << endl;
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;

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