/**
 * @file Travelling_SalesPerson.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-06-17
 * @copyright Copyright (c) 2025
 * @problem: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4/problem
 * @tag: recursion, bitmask, travelling salesman
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 12 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


/*
    let current mask is x.
    there is possibility to travel from i to j
    if j is not in mask i.e jth bit is no set.

    take all possible moves from current mask(where jth bit is not set)

*/

int n;
int g[N][N];
int lastmask;

int travel(int i, int mask){
    if(mask == lastmask){
        return g[i][0];
    }
    int ans = inf;
    for(int j=0;j<n;j++){
        if((mask & (1 << j)) == 0){
            int newmask = mask | (1 << j);
            ans = min(ans, travel(j, newmask) + g[i][j]);
        }
    }
    return ans;
}


void solve(){

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    lastmask = (1 << n) - 1;

    cout << travel(0, 0) << endl;

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