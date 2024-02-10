/*
 * @file Domino_Principle.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-10
 * @copyright Copyright (c) 2024
 * @problem: https://codeforces.com/problemset/problem/56/E
 * @approach: segment tree.
 * @explanation:
 */


/*

    (0, 10), (1, 5), (9, 10), (15, 10)
       4       1       2        1

*/


/*
    In dp approach. dp[i] = how many will fall.
    calculating dp[i]
            iterate through next dominos.
            if (falls) count it and skip the counts iterate remaining next dominos.
            else break.

    traverse from right(reverse sorted).
    array -> 1:(10, 10) 2:(16, 5) 3:(18, 2), 4:(20, 5)
    dp    -> 1: 4       2: 3      3: 1       4: 1
    dp[4] = 1;
    dp[3] = 1 -> in 4 it will not fall break.
    dp[2] = 3 -> in 3 it will fall(add 1) update ptr by 1.
                 in 4 it will fall(add 1) update ptr by 1 (end of bound).
    dp[1] = 4 -> in 2 it will fall(add 3) update ptr by 3 (end of bound).

*/



#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    

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