#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    set<int>s, ss;
    for(int i=0;i<n+1;i++){
        s.insert(i);
        ss.insert(i);
    }
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(s.find(v[i]) != s.end()){
            s.erase(v[i]);
        }
    }

    int mex = *s.begin();
    if(mex == 1){
        cout << 0 << endl;
        return;
    }
    int p = n, rp = -1;
    for(int i=0;i<n;i++){
        if(v[i] != 0){
            p = i;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(v[i] != 0){
            rp = i;
        }
    }
    for(int i=p;i<=rp;i++){
        if(ss.find(v[i]) != ss.end()){
            ss.erase(v[i]);
        }
    }
    int mex2 = *ss.begin();
    cout << mex << " " << mex2 << endl;
    if(mex2 == 0){
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

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