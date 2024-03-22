/*
 * @file Longest_Perfect_Increasing_Subsequence.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-03-21
 * @copyright Copyright (c) 2024
 * @problem: Spoj LPIS
 * @approach:
 * @explanation:
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6+10;

int freq[N];

void solve(){

    int n; cin >> n;
    vector<int>v(n+10);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        int mx = freq[v[i] - 1];
        freq[v[i]] = mx + 1;
        v[i] = mx + 1;
    }

    // for(int i=1;i<=n;i++) cout << v[i] << " "; cout << endl;
    cout << *max_element(v.begin()+1, v.begin()+n+1);

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}