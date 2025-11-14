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
    vector<int> a(n);
    vector<int> b;
    for(int i=0;i<n;i++) cin >> a[i];

    // b.push_back(a[0]);

    int cur = 0;
    while(1){
        b.push_back(a[cur]);
        int n1 = cur + 1;
        int n2 = cur + 2;
        // check for last

        if(n1 == n - 1){
            b.push_back(a[n1]);
            break;
        } 
        if(n1 >= n){
            break;
        }

        if(n2 == n - 1){
            b.push_back(a[n1]);
            b.push_back(a[n2]);
            break;
        }

        if(a[n1] <= a[n2]) {
            // b.push_back(a[n1]);
            cur = n1;
        } else {
            b.push_back(a[n2]);
            b.push_back(a[n1]);
            // b.push_back(cur+3);
            cur = cur + 3;
        }
    }

    for(auto i : b) cout << i << " "; cout << endl;

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