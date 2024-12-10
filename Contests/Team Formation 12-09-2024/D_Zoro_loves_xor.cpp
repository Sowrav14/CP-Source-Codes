#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

bool check(vector<int>a){
    for(int i=0;i<a.size()-2;i++){
        if((a[i] ^ a[i+1]) == a[i+2]){
            cout << a[i] << endl;
            return false;
        }
    }
    return true;
}

void solve(){

    int n; cin >> n;
    if(n == 3){
        cout << -1 << endl;
        return;
    }
    vector<int>ans;
    ans.push_back(1);
    ans.push_back(n);
    for(int i=2;i<n;i++) ans.push_back(i); 
    for(auto i : ans) cout << i << " "; cout << endl;
    // cout << check(ans) << endl;

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