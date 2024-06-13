#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 210;
pair<int,int>a[N];
int dp[N][N][30];

void solve(){

    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        int five = 0, two = 0;
        int c = x;
        while(c%5 == 0){
            c /= 5;
            five++;
        }
        int b = x;
        while(b%2==0){
            b /= 2;
            two++;
        }

        a[i].first = five, a[i].second = two;
    }

    for(int i=1;i<=n;i++){
        
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}