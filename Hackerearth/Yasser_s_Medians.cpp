#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int M = 1e9+7;
inline int bigmod(int x,int y)  				{int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
int n, mx, k, med;
vector<int>bit;

void update(int idx, int val){
    while(idx <= mx){
        bit[idx] += val;
        idx += (idx) & (-idx);
    }
}

int getsum(int idx){
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= (idx) & (-idx);
    }
    return sum;
}

int getmedian(){
    int l = 1, r = mx;
    int ret = -1;
    while(l <= r){
        int m = (l + r) / 2;
        int x = getsum(m);
        if(x >= med){
            ret = m;
            r = m - 1;
        } else{
            l = m + 1;
        }
    }
    return ret;
}



void solve(){

    cin >> n >> k;
    vector<int>v(n+10);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    bit.resize(mx+10, 0);
    med = (k + 1)/2;
    for(int i=1;i<=k;i++){
        update(v[i], 1);
    }
    int res = getmedian();
    for(int i=k+1;i<=n;i++){
        update(v[i-k], -1);
        update(v[i], 1);
        res = max(res, getmedian());
    }
    cout << bigmod(n, res) << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}