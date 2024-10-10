#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


double findNthRoot(double x, int n){
 
    // Initialize boundary values
    double low, high;
    if (x >= 0 and x <= 1){
        low = x;
        high = 1;
    }
    else{
        low = 1;
        high = x;
    }
 
    // Used for taking approximations
    // of the answer
    double epsilon = 0.00000001;
 
    // Do binary search
    double guess = (low + high) / 2;
    while (abs((pow(guess, n)) - x) >= epsilon) {
        if (pow(guess, n) > x){
            high = guess;
        }
        else{
            low = guess;
        }
        guess = (low + high) / 2;
    }
 
    return guess;
}


void solve(){

    int n,p; cin >> n >> p;
    double up = findNthRoot(p, n);
    double down = findNthRoot(100, n);
    
    double u = 1, d = 1;
    for(int i=1;i<n;i++){
        u *= up;
        d *= down;
    }
    // cout << u << " " << d << endl;
    double y = u / d;
    y *= 100;
    cout << fixed << setprecision(8) << y - p  << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}