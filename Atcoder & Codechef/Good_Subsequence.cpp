#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    int ans = 0;
    int flag = 0;
    for(int i=0;i<n;i++){
        if(v[i]%2 == flag){
            ans++;
            flag = 1 - flag;
        }
    }

    int res = 0;
    flag = 1;
    for(int i=0;i<n;i++){
        if(v[i]%2 == flag){
            res++;
            flag = 1 - flag;
        }
    }

    cout << max(ans, res) << endl;

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