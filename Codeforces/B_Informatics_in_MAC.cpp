#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(auto &i : v) cin >> i;

    set<int>s;
    vector<int>pref(n), suf(n);

    for(int i=0;i<=n;i++) s.insert(i);
    for(int i=0;i<n;i++){
        if(s.find(v[i]) != s.end()){
            s.erase(s.find(v[i]));
        }
        pref[i] = *s.begin();
    }

    s.clear();
    for(int i=0;i<=n;i++) s.insert(i);
    for(int i=n-1;i>=0;i--){
        if(s.find(v[i]) != s.end()){
            s.erase(s.find(v[i]));
        }
        suf[i] = *s.begin();
    }

    // for(int i=0;i<n;i++) cout << pref[i] << " "; cout << endl;
    // for(int i=0;i<n;i++) cout << suf[i] << " " ; cout << endl; 

    int pos = -1;
    for(int i=0;i<n-1;i++){
        if(pref[i] == suf[i+1]) {
            pos = i + 1;
            break;
        }
    }

    if(pos == -1){
        cout << -1 << endl;
    } else{
        cout << 2 << endl;
        cout << 1 << " " << pos << endl;
        cout << pos + 1 << " " << n << endl;
    }

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