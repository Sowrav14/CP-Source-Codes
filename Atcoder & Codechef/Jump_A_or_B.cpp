#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
int n, m, a, b;

void solve(){

    cin >> n >> m >> a >> b;
    if(a == b){
        if(n*a == m){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return;
    }
    if(a > b) swap(a, b);

    int x = (m - n*a)/(b - a);
    if(x < 0 || x > n){
        cout << "No" << endl;
        return;
    }
    if((m - n*a)%(b - a) == 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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