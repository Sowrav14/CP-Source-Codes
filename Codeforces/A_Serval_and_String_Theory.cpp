#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


bool check(string s){
    string ss = s;
    reverse(ss.begin(), ss.end());
    for(int i=0;i<s.size();i++){
        if(s[i] == ss[i]) continue;
        else if(s[i] < ss[i]) return true;
        else return false;
    }
    return false;
}


void solve(){

    int n, k; cin >> n >> k;
    string s; cin >> s;
    if(n == 1){
        cout << "NO" << endl;
        return;
    }
    // cout << check(s) << endl;
    if(check(s)) {
        cout << "YES" << endl;
        return;
    }
    if(k == 0){
        cout << "NO" << endl;
        return;
    }
    char a = s[0], b = s.back();
    if(a != b) {
        cout << "YES" << endl;
        return;
    }

    char c = '#';
    for(int i=1;i<s.size()-1;i++){
        if(s[i] != a){
            c = s[i];
        }
    }
    if(c == '#'){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

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