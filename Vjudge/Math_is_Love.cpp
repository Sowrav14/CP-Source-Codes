/*
 * @file Math_is_Love.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-17
 * @copyright Copyright (c) 2024
 * @problem:  given sum of(1...n) find n.
 * @approach: binary search.
 * @explanation:
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = 1e10;
void solve(){

    int n; cin >> n;
    int l=0, r=inf;

    while(l <= r){
        int m = (l + r) / 2;
        int sum = m * (m + 1) * 1ll;
        sum /= 2;

        if(sum == n){
            cout << m << endl;
            return;
        } else if(sum > n){
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << "NAI" << endl;

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