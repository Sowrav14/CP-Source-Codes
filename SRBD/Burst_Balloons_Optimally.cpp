/**
 * @file Burst_Balloons_Optimally.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-06-18
 * @copyright Copyright (c) 2025
 * @problem: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges
 * @tag: recursion, backtracking
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int shotBallon(vector<int> &v){
    if(v.size() == 1) return v[0];

    int ans = -inf;
    for(int i=0;i<v.size();i++){
        int score = 0;
        if(i == 0) score = v[i+1];
        else if(i == v.size() - 1) score = v[i-1];
        else score = v[i-1] * v[i+1];

        vector<int> t;
        for(int j=0;j<v.size();j++) if(j != i) t.push_back(v[j]);
        score += shotBallon(t);
        ans = max(ans, score);
    }
    return ans;
}

void solve(){

    int n; cin >> n;
    vector<int> ballon(n);
    for(int i=0;i<n;i++) cin >> ballon[i];

    cout << shotBallon(ballon) << endl;

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