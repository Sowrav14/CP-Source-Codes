#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int a = 0, b = 0, m = 0;
    int prev = v[0], i = 0;
    while(i < n and v[i] == prev) i++;
    a = i;
    int last = v[n-1];
    int j = n-1;
    while(j>=i and v[j] == last) j--;
    b = n - j - 1;
    // cout << a << " " << b << endl;
    if(v[0] == v[n-1]){
        m = a + b;
    } else {
        m = max(a, b);
    }

    cout << n - m << endl;


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