#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

/*

odds(n/2) -> 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33
2*odds(n/4) -> 2 6 10 14 18 22 26 30 34
3*odds() -> no
4*odds(n/8) -> 4 12 20 28
5*odds -> none
6*odds -> 
7*odds
8*odds(n/16) -> 8 24 

16* 16
32

s = 1, e = 34, dif = 4;

2 + k*4 = 34.
k = 32/4 = 8

4 + k*8 = 34
k = 30/8 = 3 + 1 = 4.

34  
    17
    9 2nd bit set
    4 3rd bit set
    2 4th bit set
    1 5th bit set
    1 6th bit set

 */



void solve(){

    int n,k; cin >> n >> k;
    vector<int>v;
    int x = 1;
    while(x <= n){
        int diff = x * 2;
        int k = (n - x) / diff;
        k++;
        v.push_back(k);
        // cout << x << " " << diff << " " << k << endl;
        x *= 2;
    }

    int sz = v.size();
    vector<int>pref(sz); pref[0] = v[0];
    for(int i=1;i<sz;i++){
        pref[i] = pref[i-1] + v[i];
    }

    // for(int i=0;i<sz;i++){
    //     cout << pref[i] << " ";
    // } cout << endl;

    int it = lower_bound(pref.begin(), pref.end(), k) - pref.begin();

    int diff = (1 << (it+1));

    if(it != 0){
        k -= pref[it-1];
    }

    k--;

    // cout << k << " " << diff << " " << it << endl;
    int start = ceil(diff/2.0);

    cout << start + k * diff << endl;

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