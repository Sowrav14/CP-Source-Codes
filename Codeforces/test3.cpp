#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N],dp[N];



int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = a[1];
    for(int i=2;i<=n;i++){
        dp[i] = max(a[i] + dp[i-2], dp[i-1]);
    }
    cout << dp[n] << endl;
}