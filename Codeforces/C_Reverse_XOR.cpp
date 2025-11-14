#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v;
    while(n){
        v.push_back(n%2);
        n /= 2;
    }
    // for(auto i : v) cout << i << " "; cout << endl;
    while(v.size() <= 64){
        bool f = 1;
        for(int i=0;i<v.size();i++){
            if(i == v.size() - i - 1 && v[i] == 1) f = 0;
            if(v[i] != v[v.size() - i - 1]) f = 0;
        }
        if(f){
            cout << "YES" << endl;
            return;
        } else {
            v.push_back(0);
        }
    }
    cout << "NO" << endl;

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