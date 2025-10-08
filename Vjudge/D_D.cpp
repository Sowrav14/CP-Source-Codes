#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

double ans[N];

void generate(){
    ans[0] = 0;
    ans[1] = 1;

    double sum = 1;
    for(int i=2;i<N;i++){
        double exp = (sum / i);
        exp += 1;
        ans[i] = exp;
        sum += exp;
    }
}


void solve(){

    int n; cin >> n;
    cout << fixed << setprecision(10) << ans[n] << endl;

}


signed main(){
    Fast_IO()
    generate();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}