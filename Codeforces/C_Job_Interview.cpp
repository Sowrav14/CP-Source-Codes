#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;


void solve(){

    int n,m; cin >> n >> m;
    int tot = n + m + 1;
    vector<int>p(tot+1), t(tot+1);
    for(int i=1;i<=tot;i++){
        cin >> p[i];
    }
    for(int i=1;i<=tot;i++){
        cin >> t[i];
    }

    vector<int>ans(tot+1, 0);
    // pp = 00, pt = 01, tp = 10, tt = 11
    vector<int>st(tot+1);
    int test = 0, pro = 0;
    for(int i=1;i<tot;i++){
        if(p[i] > t[i]){
            if(pro < n){
                // cout << i << " p " << endl;
                ans[tot] += p[i];
                st[i] = 0;
                pro++;
            } else{
                // cout << i << " t " << endl;
                ans[tot] += t[i];
                st[i] = 1;
                test++;
            }
        } else{
            if(test < m){
                // cout << i << " t " << endl;
                ans[tot] += t[i];
                st[i] = 3;
                test++;
            } else{
                // cout << i << " p " << endl;
                ans[tot] += p[i];
                st[i] = 2;
                pro++;
            }
        }
    }

    int tbp = -1, pbt = -1;
    for(int i=tot-1;i>=1;i--){
        if(st[i] == 0 or st[i] == 2){
            // programmer
            int sp = tot;
            if(pbt != -1){
                sp = pbt;
            }

            ans[i] = ans[sp] - p[i] + p[sp];
            // cout << i << "  p  " << sp << endl;
        } else{
            int sp = tot;
            if(tbp != -1){
                sp = tbp;
            }

            ans[i] = ans[sp] - t[i] + t[sp];
            // cout << i << "  t  " << sp << endl;
        }

        if(st[i] == 1){
            pbt = i;
        }
        if(st[i] == 2){
            tbp = i;
        }
    }

    for(int i=1;i<=tot;i++) cout << ans[i] << " "; cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}