#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s; cin >> s;

    vector<int> freq(26, 0);
    for(int i=0;i<n;i++) freq[s[i] - 'a']++;

    for(int i=1;i<n-1;i++){
        if(freq[s[i] - 'a'] > 1) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;

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