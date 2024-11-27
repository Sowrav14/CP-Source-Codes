#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>lis;
    while(n--){
        int x; cin >> x;
        int it = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
        if(it == lis.size()){
            lis.push_back(x);
        } else {
            lis[it] = x;
        }
    }
    cout << lis.size() << endl;

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