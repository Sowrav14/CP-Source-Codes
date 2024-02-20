#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    if(a == b){
        cout << 0 << endl;
        return;
    }

    vector<int>lm(n, n), rm(n, -1);
    int l=-1;
    for(int i=0;i<n;i++){
        int x = b[i];
        int flag = 0;
        for(int j=l+1;j<n;j++){
            if(a[j] == x){
                lm[i] = j;
                l = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            break;
        }
    }



    int r=n;
    for(int i=n-1;i>=0;i--){
        int x = b[i];
        int flag = 0;
        for(int j=r-1;j>=0;j--){
            if(a[j] == x){
                rm[i] = j;
                r = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            break;
        }
    }

    // for(int i=0;i<n;i++) cout << lm[i] << " "; cout << endl;
    // for(int i=0;i<n;i++) cout << rm[i] << " "; cout << endl;

    int ans = n;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            // removeing i to j
            int res = j - i + 1;
            // res = n - res;

            int x = n;
            int y = -1;

            if(i-1>=0) x = lm[i-1];
            if(j+1<n) y = rm[j+1];
            // if(i == 0 and j == 3){
            //     cout << res << endl;
            //     cout << x << " " << y << endl;
            // }
            // if(x == -1 or y == -1) break;
            if(x <= y){
                ans = min(ans, res);
            }
            // if(res == 1){
            //     cout << i << " " << j << endl;
            // }
        }
    }

    cout << ans << endl;



}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << t << ": ";
        solve();
    }
}