#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    string s; cin >> s;
    int a=0, b=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'A') a++;
        if(s[i] == 'B') b++;
    }

    cout << (a > b ? 'A' : 'B' ) << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}