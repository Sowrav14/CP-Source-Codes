#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n';
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int x = a[k-1];

    sort(a.begin(), a.end());

    int y;
    for(int i=0;i<n;i++){
        if(a[i] == x){
            y = i;
            break;
        }
    }

    int wat = 1;
    for(int i=y;i<n-1;i++){
        int diff = a[i+1] - a[i];
        wat = wat + diff - 1;
        if(wat > a[i]){
            cout << "NO" << endl;
            return;
        }
        wat++;
        // cout << i << " " << a[i] << " " << wat << endl;
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