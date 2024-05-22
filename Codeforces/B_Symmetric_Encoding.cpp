#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    string s; cin >> s;
    int a[26] = {0};
    for(int i=0;i<n;i++){
        a[s[i] - 'a'] = 1;
    }
    string r = "";
    for(int i=0;i<26;i++){
        if(a[i] == 1){
            r += char(i + 'a');
        }
    }
    // cout << r << endl;
    map<char,char>m;
    for(int i=0;i<r.size();i++){
        m[r[i]] = r[r.size()-i-1];
    }
    // for(auto i : m) cout << i.first << " " << i.second << endl;

    for(int i=0;i<n;i++){
        cout << m[s[i]];
    } cout << endl;

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