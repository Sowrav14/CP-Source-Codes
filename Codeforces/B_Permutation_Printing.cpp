#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)  v[i] = i;

    for(int i=1;2*i<=n;i+=2){
        swap(v[i], v[n-i+1]);
    }


    for(int i=1;i<=n;i++) cout << v[i] << " "; cout << endl;

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