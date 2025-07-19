#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    vector<int> ans(n+2, 0);
    ans[n+1] = n + 1;
    int k = 1;
    for(int i=1;i<=n;i++){
        if(i!= 1 and s[i-2] == s[i-1] and s[i-1] == 'B') {
            cout << -1 << endl;
            return;
        };
        if(s[i-1] == 'B'){
            ans[i] = k++;
        }
    }

    if(k == 1){
        cout << -1 << endl;
        return;
    }

    for(int i=1;i<=n+1;i++){
        if(ans[i] != 0){
            int j = i + 1;
            while(j <= n and ans[j] == 0){
                ans[j] = k++;
                j++;
            }
            j = i - 1;
            while(j >= 1 and ans[j] == 0){
                ans[j] = k++;
                j--;
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << endl;

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