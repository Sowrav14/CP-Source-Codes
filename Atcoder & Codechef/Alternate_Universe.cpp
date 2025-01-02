#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
int a[N];
int b[N];



void solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    int ans = 0;
    for(int i=n;i>=1;i--){
        int req = ans + 1;
        int curmx = a[i] + b[i];
        // cout << req << " " << curmx << endl;
        if(req <= curmx){
            if(b[i] >= req){
                ans = 0;
            } else {
                ans = req - b[i];
            }
        } else{
            ans = req;
        }
    }
    cout << ans << endl;
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