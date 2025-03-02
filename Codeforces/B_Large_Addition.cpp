#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s = to_string(n);
    
    if(s.back() == '9'){
        cout << "NO" << endl;
        return;
    }
    if(s[0] != '1'){
        cout << "NO" << endl;
        return;
    }
    for(int i=1;i<s.size()-1;i++){
        if(s[i] == '0'){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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