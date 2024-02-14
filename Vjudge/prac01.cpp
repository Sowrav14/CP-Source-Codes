#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 262144 + 10;
const int mod = 1e9+7;
int n,m;
inline int ad(int x,int y)      				{int ret=(x%mod+y%mod)%mod;   if(ret<0)   {ret+=mod,ret=ret%mod;} return ret;}
inline int gun(int x,int y)     				{int ret=((x%mod)*(y%mod))%mod;   if(ret<0)   {ret+=mod,ret=ret%mod;} return ret;}

int a[N];
int tree[4*N][20];





void build(){
    for(int i=0;i<n;i++){
        tree[n+i][a[i]%m] = 1;
    }

    for(int i=n-1;i>0;i--){
        // tree[i] = tree[i<<1] + tree[i<<1|1];
        for(int j=0;j<m;j++){
            tree[i][j] = ad(tree[i<<1][j], tree[i<<1|1][j]);
        }

        for(int l=0;l<m;l++){
            for(int r=0;r<m;r++){
                int x = (l + r) % m;
                tree[i][x] = ad(tree[i][x], gun(tree[i<<1][l], tree[i<<1|1][r]));
            }
        }
    }
}

int query(int l, int r){
    int resl[20] = {0}, resr[20] = {0};
    for(l+=n, r+=n; l<r; l >>=1 , r >>=1 ) {
        if(l&1){
            int temp[20] = {0};
            for(int i=0;i<m;i++){
                temp[i] = ad(resl[i], tree[l][i]);
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    int x = (i + j) % m;
                    temp[x] = ad(temp[x], gun(resl[i], tree[l][j]));
                }
            }
            for(int i=0;i<m;i++){
                resl[i] = temp[i];
            }
            l++;
        }
        if(r&1){
            r--;
            int temp[20] = {0};
            for(int i=0;i<m;i++){
                temp[i] = ad(resr[i], tree[r][i]);
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    int x = (i + j) % m;
                    temp[x] = ad(temp[x], gun(resr[i], tree[r][j]));
                }
            }
            for(int i=0;i<m;i++){
                resr[i] = temp[i];
            }
        }
    }

    int temp[20] = {0};
    for(int i=0;i<m;i++){
        temp[i] = ad(resl[i], resr[i]);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int x = (i + j) % m;
            temp[x] = ad(temp[x], gun(resl[i], resr[j]));
        }
    }
    return temp[0];

}



void solve(){

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int x = log2(n);
    if((1 << x) == n) n = n;
    else n = (1 << (x+1));

    build();

    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        l--;
        cout << query(l, r) + 1 << endl;
    }

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