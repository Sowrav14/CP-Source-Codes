#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = 1e18;

int calc(int x,vector<int>&a,int k){
    int moves=0,ans=0;
    vector<int>excess,receivable;
    for(int i=0;i<a.size();i++){
        if(a[i]>x){
            excess.push_back(a[i]-x);
            ans+=x*(x+1)/2;
        } else {
            ans+=a[i]*(a[i]+1)/2;
            if(a[i]<x)receivable.push_back(x-a[i]);
        }
    }
    ans+=moves*k;
    sort(excess.rbegin(),excess.rend());
    sort(receivable.begin(),receivable.end());
    int i=0,j=0;
    while(i<excess.size()&&j<receivable.size()){
        int take=min(excess[i],receivable[j]);
        moves+=take;
        receivable[j]-=take;
        excess[i]-=take;
        if(receivable[j]==0)j++;
        if(excess[i]==0)i++;
    }
    ans+=moves*k;
    for(int v:receivable){
        if(v>0)ans+=v*(v+1)/2;
    }
    return ans;
}

void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    int s=0,mx=0;
    for(int i=0;i<n;i++)cin>>a[i],s+=a[i],mx=max(mx,a[i]);
    if(n==1){cout<<a[0]*(a[0]+1)/2<<'\n';return;}
    int l=s/n,r=mx,ans=inf;
    while(r-l>3){
        int m1=l+(r-l)/3,m2=r-(r-l)/3;
        int f1=calc(m1,a,k),f2=calc(m2,a,k);
        if(f1<=f2)r=m2;
        else l=m1;
    }
    for(int i=l;i<=r;i++)ans=min(ans,calc(i,a,k));
    cout<<ans<<'\n';
}

signed main(){
    Fast_IO()
    int t;cin>>t;
    while(t--)solve();
}