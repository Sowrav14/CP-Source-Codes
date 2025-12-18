#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, m;
vector<int> S, pref;
vector<long long> dp_before, dp_cur;

/*
Multi line comment for explanation before functions:

C(l, r) returns cost of assigning prisoners from l to r to one guard.
Cost formula = (r-l+1) * (sum of S[l..r])
We compute sum fast using pref[].

compute(l, r, optl, optr):
This is divide & conquer optimization to compute dp for one layer.
It finds optimal k in [optl, optr] for each mid in [l, r].

solve():
Main dp driver.
dp_before[i] = C(0, i) for the first guard.
For each guard group, compute dp_cur via divide & conquer.
Return dp_before[n-1].
*/

long long C(int l, int r){
    long long sum = pref[r] - (l ? pref[l-1] : 0);
    long long len = r - l + 1;
    return sum * len;
}

void compute(int l, int r, int optl, int optr){
    if(l > r) return;
    int mid = (l + r) >> 1;
    pair<long long,int> best = {LLONG_MAX, -1};
    for(int k = optl; k <= min(mid, optr); k++){
        long long val = (k ? dp_before[k-1] : 0) + C(k, mid);
        if(val < best.first) best = {val, k};
    }
    dp_cur[mid] = best.first;
    int opt = best.second;
    compute(l, mid-1, optl, opt);
    compute(mid+1, r, opt, optr);
}

void solve(){
    cin >> n >> m;
    S.resize(n);
    pref.resize(n);
    for(int i=0;i<n;i++){
        cin >> S[i];
        pref[i] = S[i] + (i ? pref[i-1] : 0);
    }

    dp_before.assign(n, 0);
    dp_cur.assign(n, 0);

    for(int i=0;i<n;i++){
        dp_before[i] = C(0, i);
    }

    for(int g=1; g<m; g++){
        compute(0, n-1, 0, n-1);
        dp_before = dp_cur;
    }

    cout << dp_before[n-1] << endl;
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
