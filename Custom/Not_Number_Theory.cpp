#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void recur(int i, string s, vector<string>&v){
    if(i == s.size()){
        v.push_back(s);
        return;
    }

    if(s[i] == '?'){
        for(char c='0';c<='9';c++){
            s[i] = c;
            recur(i+1, s, v);
        }
    } else{
        recur(i+1, s, v);
    }
}



void solve(){

    string s; cin >> s;
    vector<string>v;
    int ans = INT_MAX;
    int cnt = 0;
    recur(0, s, v);
    for(auto i : v){
        // cout << i << endl;
        int x = stoi(i);
        int setb = __builtin_popcount(x);
        if(setb > cnt){
            ans = x;
            cnt = setb;
        } else if(setb == cnt){
            ans = max(ans, x);
        }
    }
    cout << ans << endl;
    // cout << cnt << endl;

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