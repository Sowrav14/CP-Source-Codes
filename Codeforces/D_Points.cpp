#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define ordered_set tree<int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;

class points{
    public:
        string type;
        int x,y;
        points(){}
        points(string s, int xx, int yy){
            type = s;
            x = xx;
            y = yy;
        }
}; points p[N];
int xc[N], yc[N];

void build(){

}

void update(){

}
int query(){
    
}



void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        int xx,yy; cin >> xx >> yy;
        p[i] = points(s, xx, yy);
        
    }
    
    for(int i=1;i<=n;i++){
        int x = p[i].x;
        int y = p[i].y;
        
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