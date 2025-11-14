#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    string s; cin >> s;
    vector<int> a(26, 0);
    for(char i : s){
        a[i-'a']++;
    }

    int f = 0;
    for(int i=0;i<26;i++){
        if(a[i]%2) f++;
    }
    if(f > 1) cout << "no" << endl;
    else cout << "yes" << endl;

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