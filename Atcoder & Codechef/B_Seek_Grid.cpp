#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    char s[n][n], t[m][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> s[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> t[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+m > n) continue;
            if(j+m > n) continue;

            int flag = 1;
            for(int it=0;it<m;it++){
                for(int jt=0;jt<m;jt++){
                    // cout << i << " " << j << " " << it << " " << jt << endl;
                    if(s[i+it][j+jt] != t[it][jt]){
                        flag = false;
                        // cout << i << " " << j << " " << it << " " << jt << endl;
                    }
                }
            }
            // cout << "HERE" << endl;
            if(flag){
                cout << i+1 << " " << j+1 << endl;
                return;
            }
        }
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}