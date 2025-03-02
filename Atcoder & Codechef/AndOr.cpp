#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    vector<int>pref(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    pref[0] = v[0];
    for(int i=1;i<n;i++){
        if(i%2){
            pref[i] = pref[i-1] & v[i];
        } else {
            pref[i] = pref[i-1] | v[i];
        }
    }

    int q; cin >> q;
    while(q--){
        int p, x;
        cin >> p >> x;
        p--;
        v[p] = x;
        for(int i=p;i<n;i++){
            if(i == 0){
                int ne = v[i];
                if(ne == pref[i]) break;
                pref[i] = ne;
            } else if(i%2){
                int ne = pref[i-1] & v[i];
                if(ne == pref[i]) break;
                pref[i] = ne;
            } else {
                int ne = pref[i-1] | v[i];
                if(ne == pref[i]) break;
                pref[i] = ne;
            }
        }

        cout << pref[n-1] << endl;
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