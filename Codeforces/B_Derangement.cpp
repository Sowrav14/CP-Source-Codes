#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a;
    int fixed = 1;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        if(x == i) a.push_back(x);
        else fixed = i;
    }
    if(a.size() % 2){
        a.push_back(fixed);
    }

    cout << a.size() / 2 << endl;
    for(int i=1;i<a.size();i+=2){
        cout << a[i-1] << " " << a[i] << endl;
    }

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