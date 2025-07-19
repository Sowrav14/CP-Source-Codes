#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    string s; cin >> s;
    vector<int> v;
    for(int i=0;i<s.size();i++){
        if(s[i] == '.') continue;
        v.push_back(i+1);
    }

    for(int i=1;i<v.size();i+=2){
        cout << v[i-1] << "," << v[i] << endl;
    }

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