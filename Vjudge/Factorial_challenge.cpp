// #include<bits/stdc++.h>
// using namespace std;
// #define int long long int
// #define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// const int N = 1e6+10;
// int digit[N];


// Logarithmic approximation O(logn).
// void gen(){
//     digit[1] = 1;
//     double digits = 0;
//     for(int i=2;i<N;i++){
//         digits += log10(i);
//         digit[i] = floor(digits) + 1;
//     }
// }


// void solve(){

//     int n; cin >> n;
    
//     int l = 1, r = N - 2;
//     int ans;
//     while(l <= r){
//         int m = (l + r) / 2;

//         int d = digit[m];
//         if(d <= n){
//             ans = m;
//             l = m + 1;
//         } else {
//             r = m - 1;
//         }
//     }

//     cout << ans << endl;

// }


// signed main(){
//     Fast_IO()
//     gen();
//     int t = 1;
//     cin >> t;
//     for(int i=1;i<=t;i++){
//         // cout << "Case " << t << ": ";
//         solve();
//     }
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e9;


// Stirling approximation O(1).
int digit(int n)
{
    if (n < 0) {
        return 0;
    }
    if (n <= 1) {
        return 1;
    }
    double x
        = (n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0);
    return floor(x) + 1;
}


void solve(){

    int n; cin >> n;
    // cout << digit(5) << endl;

    int l = 1, r = N;
    int ans;
    while(l <= r){
        int m = (l + r) / 2;
        int d = digit(m);
        if(d <= n){
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << endl;

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