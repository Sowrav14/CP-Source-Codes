#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int r,c; cin >> r >> c;
    char grid[r][c];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> grid[i][j];
        }
    }

    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i=0;i<r;i++){
        int j = 0;
        string s = "";
        while(j < c){
            if(grid[i][j] == 'X') {
                if(s.size() >= 2) ans = min(ans, s);
                s = "";
                j++;
            } else{
                s += grid[i][j];
                j++;
            }
        }
        if(s.size() >= 2) ans = min(ans, s);
    }

    for(int j=0;j<c;j++){
        int i = 0;
        string s = "";
        while(i < r){
            if(grid[i][j] == 'X') {
                if(s.size() >= 2) ans = min(ans, s);
                s = "";
                i++;
            } else{
                s += grid[i][j];
                i++;
            }
        }
        if(s.size() >= 2) ans = min(ans, s);
    }

    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ": ";
        solve();
    }
}