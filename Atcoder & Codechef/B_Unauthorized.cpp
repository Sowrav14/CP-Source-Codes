#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int d; cin >> d;
    int flag = 0, cnt = 0;;
    for(int i=0;i<d;i++){
        string s; cin >> s;
        if(s == "login") flag = 1;
        else if(s == "logout") flag = 0;
        else if(s == "public"){
            continue;
        } else {
            if(!flag) cnt++;
        }
    }
    cout << cnt << endl;

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