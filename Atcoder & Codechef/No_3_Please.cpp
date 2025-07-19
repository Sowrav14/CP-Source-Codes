#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n, 0);
    int pos = n+1, pref = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        pref += a[i];
        if(pref % 3 == 0) pos = i;
    }
    if(pos == n+1){
        cout << "Yes" << endl;
        return;
    }
    for(int i=0;i<min(n, 200ll);i++){
        reverse(a.begin(), a.begin()+(int)i+1);
        pref = 0;
        pos = -1;
        for(int j=0;j<n;j++){
            pref += a[j];
            if(pref % 3 == 0) pos = j;
        }
        if(pos == -1){
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