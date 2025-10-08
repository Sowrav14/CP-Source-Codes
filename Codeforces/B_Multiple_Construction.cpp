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
    vector<int> a(2*n, 0);

    int l = 0;

    for(int i=n;i>=1;i--){
        while(a[l] != 0) l++;
        int r = l + i;
        while(a[r] != 0) r += i;
        a[l] = a[r] = i; 
    }
    for(int i=0;i<2*n;i++) cout << a[i] << " "; cout << endl;

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