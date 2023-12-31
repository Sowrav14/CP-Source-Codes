#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n,k; cin >> n >> k;
    int mul = 1;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        mul *= x;
    }

    int rem = (2023 / mul);
    if(rem * mul == 2023){
        cout << "YES" << endl;
        cout << rem << " ";
        for(int i=0;i<k-1;i++) cout << 1 << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}