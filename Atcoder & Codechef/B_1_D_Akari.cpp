#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    string s; cin >> s;
    int lh = -1, lo = -2;
    for(int i=0;i<s.size();i++){
        if(s[i] == '#'){
            lh = i;
        } else {
            if(lh > lo){
                s[i] = 'o';
                lo = i;
            } else {
                s[i] = '.';
            }
        }
    }
    cout << s << endl;

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