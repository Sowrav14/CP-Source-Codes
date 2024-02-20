#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    int a[n][n] = {0};
    int r = 0;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<n;j++){
            a[i][j] = s[j] - '0';
            if(a[i][j] == 1) r = i;
        }
    }

    int b =0, c=0;
    int next = r-1;

    for(int i=0;i<n;i++){
        b += a[r][i];
    }
    for(int i=0;i<n;i++){
        c += a[next][i];
    }
    // cout << r << " " << next << endl;
    // cout << b << " " << c << endl;
    if(b == c){
        cout << "SQUARE" << endl;
    } else{
        cout << "TRIANGLE" << endl;
    }

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