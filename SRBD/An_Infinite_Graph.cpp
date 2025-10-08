#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

bool isPrime[N];
int primeId[N];
int minPrime[N];
vector<int> primes;

void sieve(){
    for(int i=2;i<N;i++) isPrime[i] = 1;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            primes.push_back(i);
            primeId[i] = primes.size();
            for(int j=i+i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }

    for(int i=4;i<N;i+=2){
        for(auto p : primes){
            if(isPrime[i-p]) {
                minPrime[i] = p;
                break;
            }
        }
    }
}


void solve(){

    int n; cin >> n;

    if(n == 2){
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 0 << endl;
        return;
    }

    int p = minPrime[n];
    int q = n - p;

    int dist = 0;
    int i = primeId[p], j = primeId[q];
    while(i != j){
        dist++;
        if(i < j) swap(i, j);
        i /= 2;
    }

    cout << 2 << endl;
    cout << p << " " << q << endl;
    cout << dist << endl;

}


signed main(){
    Fast_IO()
    sieve();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}