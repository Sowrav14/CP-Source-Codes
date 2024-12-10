#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m, d1, d2; cin >> n >> m >> d1 >> d2;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin >> c;
            a[i][j] = (c == 'V' ? -1 : 0);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == -1){
                if(i-1 >= 0){
                    if(a[i-1][j] != -1) a[i-1][j] = max(a[i-1][j], d1);
                }
                if(i+1 < n){
                    if(a[i+1][j] != -1) a[i+1][j] = max(a[i+1][j], d1);
                }
                if(j-1 >= 0){
                    if(a[i][j-1] != -1) a[i][j-1] = max(a[i][j-1], d1);
                }
                if(j+1 < m){
                    if(a[i][j+1] != -1) a[i][j+1] = max(a[i][j+1], d1);
                }

                if(i-1 >= 0 and j-1 >= 0){
                    if(a[i-1][j-1] != -1) a[i-1][j-1] = max(a[i-1][j-1], d2);
                }
                if(i-1 >= 0 and j+1 < m){
                    if(a[i-1][j+1] != -1) a[i-1][j+1] = max(a[i-1][j+1], d2);
                }
                if(i+1 < n and j-1 >= 0){
                    if(a[i+1][j-1] != -1) a[i+1][j-1] = max(a[i+1][j-1], d2);
                }
                if(i+1 < n and j+1 < m){
                    if(a[i+1][j+1] != -1) a[i+1][j+1] = max(a[i+1][j+1], d2);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == -1){
                cout << "V";
            } else {
                cout << a[i][j];
            }
        } cout << endl;
    }
    cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Airplane #" << i << ":" << endl;;
        solve();
    }
}