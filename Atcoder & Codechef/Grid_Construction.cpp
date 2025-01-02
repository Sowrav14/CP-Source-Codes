#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    int x = (n + 1) / 2;
    int grid[n+1][n+1];

    vector<int>v;
    for(int i=1;i<=n;i++) v.push_back(i);
    int rot = 0;
    for(int i=x;i<=n;i++){
        int cnt = 0;
        int j = rot;
        while(cnt < n){
            cnt++;
            grid[i][cnt] = v[j%n];
            j++;
        }
        rot++;
    }

    for(int i=1;i<x;i++){
        int cnt = 0;
        int j = rot;
        while(cnt < n){
            cnt++;
            grid[i][cnt] = v[j%n];
            j++;
        }
        rot++;
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << grid[i][j] << " ";
        } cout << endl;
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