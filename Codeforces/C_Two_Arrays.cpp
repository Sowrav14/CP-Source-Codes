#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


/*
    a -> non decreasing array of length m where a[i] = [1, n]
    b -> non increasing array of length m where b[i] = [1, n]
    for each i, a[i] <= b[i]
    How many arrays are that satisfy those conditions for given n and m?

    Answer : 
        Suppose a1, a2, ..., am, bm, bm-1, ..., b1 are the elements both array that satisfy
        the condition. Then we can think of the problem as stars and bars problem.
        Where we have 2m stars(array elements) and n bars(numbers from 1 to n).
        The number of ways to arrange these stars and bars is given by the formula:
        (n + 2m - 1) C ( 2m )
        = (n + 2m - 1)! / (2m! * (n - 1)!)
*/


int bigmod(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}


void solve(){

    int n, m; cin >> n >> m;
    int up = n + 2 * m - 1;
    int down1 = 2 * m;
    int down2 = n - 1;
    int ans = 1, x = 1;
    for(int i=1; i<=up;i++){
        x = (x * i) % M;
    }
    ans = (ans * x) % M;
    x = 1;
    for(int i=1;i<=down1;i++) x = (x * i) % M;
    ans = (ans * bigmod(x, M-2)) % M;
    x = 1;
    for(int i=1;i<=down2;i++) x = (x * i) % M;
    ans = (ans * bigmod(x, M-2)) % M;
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