#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    int first0 = n+1, last0 = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        if(v[i] == 0){
            first0 = i;
            break;
        }
    }

    for(int i=n;i>=1;i--){
        if(v[i] == 0){
            last0 = i;
            break;
        }
    }

    if(first0==n+1 and last0==0){
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }

    // one zero
    if(first0 == last0){
        if(first0 == n){
            cout << 2 << endl;
            cout << n-1 << " " << n << endl;
            cout << 1 << " " << n-1 << endl;
        } else if(first0 == 1){
            cout << 2 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 1 << " " << n-1 << endl;
        } else {
            cout << 2 << endl;
            cout << 1 << " " << first0 << endl;
            cout << 1 << " " << n - first0+1 << endl;
        }
    } else if(first0 == last0-1){
        cout << 2 << endl;
        cout << first0 << " " << last0 << endl;
        cout << 1 << " " << n-1 << endl;
    } else {
        if(first0 == 1){
            cout << 3 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 2 << " " << n-1 << endl;
            cout << 1 << " " << 2 << endl;
        } else {
            cout << 3 << endl;
            cout << 1 << " " << first0 << endl;
            cout << 2 << " " << n-first0+1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        
    }

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