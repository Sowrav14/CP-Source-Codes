#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 1e5 + 10;
int used[N];

void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x, p; cin >> x >> p;
        int lst = i - p - 1;
        int cnt = 0;
        for(int d=1;d*d<=x;d++){
            if(x%d == 0){
                int a = d;
                int b = x / d;

                if(used[a] <= lst) cnt++;
                used[a] = i;

                if(a == b) continue;

                if(used[b] <= lst) cnt++;
                used[b] = i;
            }
        }
        cout << cnt << endl;
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