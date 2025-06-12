#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> r;
    vector<int> rw;
    vector<int> wb;
    vector<int> b;

    for(int i=0;i<s.size();i++){
        if(s[i] == 'R') r.push_back(i);
        else if(s[i] == 'B') b.push_back(i);
        else {
            if(wb.size() == m) rw.push_back(i);
            else wb.push_back(i);
        }
    }


    int i = 0;
    while(i < n){
        if(r[i] > rw[i]){
            cout << "NO" << endl;
            return;
        }
        i++;
    }
    int j = 0;
    while(j < m){
        if(wb[j] > b[j]){
            cout << "NO" << endl;
            return;
        }
        j++;
    }
    cout << "YES" << endl;

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