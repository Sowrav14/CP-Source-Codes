/**
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-06-17
 * @copyright Copyright (c) 2025
 * @problem:
 * @tag: Greedy or Recursion and Backtracking
 */


// #include<bits/stdc++.h>
// using namespace std;
// void toggle (vector<vector<int> >&v, int i){
//     int n = v.size();
//     for(int j=0;j<n;j++){
//         v[j][i] = !(v[j][i]);
//     }
// }
// int count(vector<vector<int> >&v){
//     int count = 0;
//     int n = v.size();
//     int m = v[0].size();
//     for(int i=0;i<n;i++){
//         int flag = 0;
//         for (int j=0;j<m;j++){
//             if(v[i][j]==0){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(!flag){
//             count++;
//         }
//     }
//     return count;
// }
// void backtrack(vector<vector<int> >&v, int& ans, int k){
//     if(k<=0){
//         ans = max(ans,count(v));
//         return;
//     }
//     for(int i=0;i<v[0].size();i++){
//         toggle(v,i);
//         backtrack(v,ans,k-1);
//         toggle(v,i);
//     }
// }
// int main(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<vector<int> >v(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>v[i][j];
//         }
//     }
//     int ans = 0;
//     backtrack(v,ans,k);
//     cout<<ans<<endl;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n,m,k; cin >> n >> m >> k;
    map<string, int> freq;

    for(int i=0;i<n;i++){
        int z = 0;
        string s = "";
        for(int j=0;j<m;j++){
            int x; cin >> x;
            if(x == 0) z++;
            s += (char)(x + '0');
        }
        if(z <= k and (k-z)%2 == 0)freq[s]++;
    }
    int ans = 0;
    for(auto i : freq){
        ans = max(ans, i.second);
    }
    cout << ans << endl;

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