#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


// 2 1 3 5 4 7 6 9 8 11 10
int a[N];

void solve(){

    int n; cin >> n;
    if(n <= 3){
        for(int i=1;i<=n;i++){
            cout << a[i] << " ";
        } cout << endl;
        return;
    }
    for(int i=4;i+1<=n;i+=2){
        a[i] = i + 1;
        a[i+1] = i;
    }
    if(n%2 == 0) a[n] = n;

    for(int i=1;i<=n;i++) cout << a[i] << " "; cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    a[1] = 2;
    a[2] = 1;
    a[3] = 3;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}