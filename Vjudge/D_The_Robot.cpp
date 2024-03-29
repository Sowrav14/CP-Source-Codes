#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    string s; cin >> s;
    int n = s.size();
    vector<pair<int,int>> points;
    int x = 0, y = 0;

    for(int i=0;i<n;i++){
        if(s[i] == 'R') x++;
        else if(s[i] == 'L') x--;
        else if(s[i] == 'U') y++;
        else y--;
        points.push_back({x,y});
    }

    for(int i=0;i<n;i++){
        int px = points[i].first, py = points[i].second;
        int x = 0, y = 0;
        for(int i=0;i<n;i++){
            int tx = x, ty = y;
            if(s[i] == 'R') x++;
            else if(s[i] == 'L') x--;
            else if(s[i] == 'U') y++;
            else y--;
            if(x == px and y == py){
                x = tx,y = ty;
            }
        }
        if(x == 0 and y == 0){
            cout << px << " " << py << endl;
            return;
        }
    }
    cout << "0 0" <<endl;

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