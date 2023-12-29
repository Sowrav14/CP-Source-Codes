#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    string ans = "";
    for(int i=n-1;i>=0;i--){
        if(s[i] == 'b' or s[i] == 'c' or s[i] == 'd'){
            ans += s[i];
            ans += s[i-1];
            ans += s[i-2];
            ans += '.';
            i -= 2;
        } else {
            ans += s[i];
            ans += s[i-1];
            ans += '.';
            i -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 1;i<ans.size();i++){
        cout << ans[i];
    } cout << endl;

}


int main(){
    int t; cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}