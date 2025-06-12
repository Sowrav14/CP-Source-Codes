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
    string ret = "";
    char x = '$';
    for(int i=0;i<n-1;i++){
        if(x == '$'){
            if(s[i] > s[i+1]){
                x = s[i];
            } else {
                ret += s[i];
            }
        } else if(x == '#'){
            ret += s[i];
        } else {
            if(s[i] <= x){
                ret += s[i];
            } else {
                ret += x;
                ret += s[i];
                x = '#';
            }
        }
    }

    if(x == '$' or x == '#'){
        ret += s[n-1];
    } else {
        if(s[n-1] <= x){
            ret += s[n-1];
            ret += x;
        } else {
            ret += x;
            ret += s[n-1];
        }
    }
    cout << ret << endl;

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