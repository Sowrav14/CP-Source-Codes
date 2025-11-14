#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 100 + 10;
const int NN = 100 * 100 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int a[N];
int n;
int dp[N][NN];

bool isSubsetSumRec(int i, int sum) {
  
    // Base Cases
    if (sum == 0)
        return dp[i][sum] = true;
    if (i == n)
        return false;

    if(dp[i][sum] != -1) return dp[i][sum];
    if (a[i] > sum)
        return dp[i][sum] = isSubsetSumRec(i + 1, sum);
    return dp[i][sum] = isSubsetSumRec(i + 1, sum) || isSubsetSumRec(i + 1, sum - a[i]);
}

vector<int> v;

void recur(int i, int sum){
    if(sum == 0) return;
    if(i == n) return;

    if(dp[i+1][sum] == 1) {
        recur(i+1, sum);
    } else if(dp[i+1][sum - a[i]] == 1){
        v.push_back(i);
        recur(i+1, sum - a[i]);
    }
}

void solve(){

    cin >> n;
    memset(dp, -1, sizeof(dp));
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }

    if(sum % 2) return cout << -1 << endl, void();
    sum /= 2;
    bool flag = isSubsetSumRec(0, sum);
    if(!flag) return cout << -1 << endl, void();
    // cout << "flag " << flag << endl;

    recur(0, sum);


    vector<int> alice, bob;
    for(auto i : v){
        alice.push_back(a[i]);
        a[i] = -1;
    }
    for(int i=0;i<n;i++){
        if(a[i] != -1) bob.push_back(a[i]);
    }

    // cout << alice.size() << " " << bob.size() << endl;
    int a = 0, b = 0;
    int ai = 0, bi = 0;
    for(int i=0;i<n;i++){
        if(a <= b){
            cout << alice[ai] << " ";
            a += alice[ai];
            ai++;
        } else {
            cout << bob[bi] << " ";
            b += bob[bi];
            bi++;
        }
    }
    cout << endl;

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