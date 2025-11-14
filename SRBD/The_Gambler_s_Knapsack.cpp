#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2005;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Expected value DP:
E[c] = average over all items i with w[i] <= c of (v[i] + E[c - w[i]])
If no item fits, E[c]=0.
Compute from c=0..W, using modular inverse for division.
*/

int modpow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=res*a%M;
        a=a*a%M;
        b>>=1;
    }
    return res;
}

void solve(){
    int n,W; cin>>n>>W;
    vector<int>w(n),v(n);
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>E(W+1,0);
    for(int c=1;c<=W;c++){
        vector<int>idx;
        for(int i=0;i<n;i++) if(w[i]<=c) idx.push_back(i);
        int k=idx.size();
        if(k==0){E[c]=0;continue;}
        int sum=0;
        for(auto i:idx){
            sum=(sum+v[i]+E[c-w[i]])%M;
        }
        int inv=modpow(k,M-2);
        E[c]=sum*inv%M;
    }
    cout<<E[W]%M<<endl;
}


signed main(){
    Fast_IO()
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
