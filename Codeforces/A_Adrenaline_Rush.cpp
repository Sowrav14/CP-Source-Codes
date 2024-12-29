#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int a[N];

void gg(){
    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        a[v[i]] = i + 1;
    }

    vector<int>ord;
    for(int i=1;i<=n;i++) ord.push_back(i);
    vector<pair<int,int>>ans;
    for(int i=n-1;i>=0;i--){
        int x = v[i];
        int pos;
        for(int j=0;j<n;j++){
            if(ord[j] == x){
                pos = j;
            }
        }

        // overtake fronts
        for(int j=pos-1;j>=0;j--){
            ans.push_back({x, ord[j]});
        }
        // reverse overtake.
        vector<int>nord;
        vector<int>vis(n, 0);
        for(int j=0;j<n;j++){
            if(j == pos) continue;
            int y = ord[j];
            int xf = a[x];
            int yf = a[y];

            if(xf > yf){
                ans.push_back({y, x});
                nord.push_back(y);
                vis[j] = 1;
            }
        }
        nord.push_back(x);
        for(int j=0;j<n;j++){
            if(j == pos or vis[j] == 1) continue;
            nord.push_back(ord[j]);
        }
        // cout << x << " " << ans.size() << " -- ";
        // for(auto i : nord) {
        //     cout << i << " ";
        // } cout << endl;
        ord = nord;
    }

    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << " " << i.second << endl;
    }
}

/* void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        a[v[i]] = i;
    }
    vector<pair<int,int>>ans;
    // for(int i=n;i>=1;i--){
    //     int x = v[i];
    //     for(int y=x-1;y>=1;y--){
    //         ans.push_back({x, y});
    //     }
    // }
    // vector<pair<int,int>>ans;
    for(int i=n;i>=1;i--){
        for(int j=i-1;j>=1;j--){
            ans.push_back({i, j});
        }
        for(int j=i-1;j>=1;j--){
            int x = a[i];
            int y = a[j];

            if(y < x){
                ans.push_back({j, i});
            }
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << " " << i.second << endl;
    }

} */


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        gg();
    }
}