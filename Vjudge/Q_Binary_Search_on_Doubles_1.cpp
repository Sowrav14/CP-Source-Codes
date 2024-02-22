/*
 * @file Q_Binary_Search_on_Doubles_1.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-22
 * @copyright Copyright (c) 2024
 * @problem: given d. find a,b such that a+b=d and a*b=d
 * @approach: binary search on doubles.
 * @explanation:
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const float eps = 1e-6;
const float e = 1e-9;


void solve(){

    double n; cin >> n;
    if(n == 0) { 
        cout << "Y " << 0 << " " << 0 << endl;
        return;
    }

    int k = 300;
    double l = 0.0, r = n * 1.0;
    double a = 0.0, b = 1e18;
    while(k--){
        a = (l + r) / 2;
        if(fabs(a - 0.0) < e) break;
        b = 1.0 * n/a;
        if(a+b > 1.0*n) r = a;
        else l = a;
    }

    if(fabs(a+b-a*b)<=eps and fabs(a*b-1.0*n)<=eps and fabs(a+b-n)<=eps)
        cout << "Y " << fixed << setprecision(9) << a << ' ' << b << endl;
    else 
        cout << "N" << endl;
    
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