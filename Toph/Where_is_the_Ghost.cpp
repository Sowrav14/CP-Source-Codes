#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e4 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct primes{
    int two = 0;
    int three = 0;
    int five = 0;
    int seven = 0;
};

int n;
vector<primes>v;

int dp[N][4][3][2][2];

int ghostbuster(int i, int two, int three, int five, int seven){
    if(i == n){
        if(five == 1 and seven == 1 and three == 2 and two == 3){
            return 1;
        } else {
            return 0;
        }
    }
    if(dp[i][two][three][five][seven] != -1) return dp[i][two][three][five][seven];

    int ans = 0;
    ans = (ans%M + ghostbuster(i+1, two, three, five, seven)%M)%M;
    int nfive = five + v[i].five > 1 ? 1 : five + v[i].five;
    int nseven = seven + v[i].seven ? 1 : seven + v[i].seven;
    int nthree = three + v[i].three > 2 ? 2 : three + v[i].three;
    int ntwo = two + v[i].two > 3 ? 3 :  two + v[i].two;
    ans = (ans%M + ghostbuster(i+1, ntwo, nthree, nfive, nseven)%M)%M;

    return dp[i][two][three][five][seven] = ans;
}

void solve(){

    cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        primes p;
        while(x%2 == 0 and x > 0) {p.two++; x /= 2;}
        while(x%3 == 0 and x > 0) {p.three++; x /= 3;}
        while(x%5 == 0 and x > 0) {p.five++; x /= 5;}
        while(x%7 == 0 and x > 0) {p.seven++; x /= 7;}
        v.push_back(p);
    }

    primes temp;
    memset(dp, -1, sizeof(dp));
    cout << ghostbuster(0, 0, 0, 0, 0) << endl;
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