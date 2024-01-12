#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n; cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        char x; cin >> x;
        if(x == '-') sum--;
        else sum++;
    }
    cout << abs(sum) << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}