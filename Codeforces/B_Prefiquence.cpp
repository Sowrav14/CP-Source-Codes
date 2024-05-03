#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,m; cin >> n >>m;
    string a,b; cin >> a >> b;

    int j = 0, ans = 0;;
    for(int i=0;i<n;i++){
        while(j < m){
            if(b[j] == a[i]){
                j++;
                ans = i + 1;
                break;
            }
            j++;
        }
        if(j == m) break;
    }

    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}