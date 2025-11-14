#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<string> times = {"00:00", "11:11", "22:22"};

void solve(){

    string s; cin >> s;
    int cur = stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
    string ans = "00:00";
    for(auto x : times){
        int v = stoi(x.substr(0,2))*60 + stoi(x.substr(3,2));
        if(cur <= v){
            ans = x;
            break;
        }
    }
    cout << ans << endl;
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
