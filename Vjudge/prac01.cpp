#include<bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define testing cout << "testing ";
#define mod 1000000007
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int tree[800008];
int arr[200002];


int query(int node,int b,int e,int i, int j){

    if(i>e or j<b) return -1;
    if(b>=i and e<=j) return tree[node];

    int left=node*2;
    int right =node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return max(p1,p2);
}

void update(int node,int b,int e,int i,int newvalue){
    if(i>e or i<b) return;
    if(b>=i and e<=i){
        tree[node]=newvalue;
        return;
    }
    int left=2*node;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=max(tree[left],tree[right]);
}



void do_the_honour(){

    int n;cin >> n;

    vector<pair<int,int>>vp;

    for(int i=0;i<4*n+4;i++) tree[i]=0;

    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        vp.push_back({x,-y});
    }

    sort(vp.begin(),vp.end());

    int ans=0;
    for(int i=n-1;i>=0;i--){
        if(i==n-1) ans++;
        else{
            if(query(1,0,n-1,i+1,n-1)<=-vp[i].second) ans++;
        }
        update(1,0,n-1,i,-vp[i].second);
    }

    cout << ans << endl;

}

int main(){
    optimize();
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++){


    do_the_honour();


}
    return 0;
}