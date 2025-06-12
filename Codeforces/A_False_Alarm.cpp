#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i=0;i<n;i++){
        if(a[i] == 1){
            int j = i;
            int cnt = 0;
            while(j < n and cnt < k){
                if(a[j] == 1) a[j] = 0;
                cnt++;
                j++;
            }
            break;
        }
    }

    for(int i=0;i<n;i++){
        if(a[i] == 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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