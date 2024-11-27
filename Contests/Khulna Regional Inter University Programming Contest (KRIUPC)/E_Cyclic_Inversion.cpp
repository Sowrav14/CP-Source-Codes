#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;


#define ordered_set         tree<pair<int,int>, null_type, less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;



void solve(int tt,int zz){

    int n;cin >> n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<int>v(n+8);
    ordered_set s;



    int inv=0;
    for(int i=1;i<=n;i++){
            int k=s.order_of_key({a[i],6e5});
            inv+=s.size()-k;
            s.insert({a[i],i});
    }



    v[1]=inv;
    for(int i=1;i<n;i++){
            s.erase({a[i],i});
            int k=s.order_of_key({a[i],-1});
            int kk=s.order_of_key({a[i],6e5});
            int l=s.size()-kk;
            inv-=k;
            inv+=l;
            s.insert({a[i],i});
            v[i+1]=inv;
    }

    int x=1e17;
    for(int i=1;i<=n;i++) x=min(x,v[i]);
    int y=1e17;
    for(int i=1;i<=n;i++) y=min(y,v[i]);
    int z=min(v[1],v[n/2+1]);

    vector<int>vv;
    if(n&1){
        for(int i=1;i<n;i++) vv.push_back(x);

    }
    else{
        for(int i=1;i<n;i++){
            if(i==(n/2)) vv.push_back(z);
            else if(i&1) vv.push_back(x);
            else vv.push_back(y);
        }
    }


    for(int i=0;i<vv.size();i++) cout  << vv[i]<<" \n"[i==vv.size()-1];




}


signed main(){
    Fast_IO()
    int t = 1;
     cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve(i,t);
    }
}
