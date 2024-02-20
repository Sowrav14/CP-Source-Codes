#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>aa(n), bb(n);
    for(int i=0;i<n;i++){
        cin >> aa[i];
    }
    for(int i=0;i<n;i++){
        cin >> bb[i];
    }
    int left = -1, right = n;
    for(int i=0;i<n;i++){
        if(aa[i] != bb[i]){
            break;
        }
        left = i;
    }
    for(int i=n-1;i>=0;i--){
        if(aa[i] != bb[i]){
            break;
        }
        right = i;
    }

    vector<int>a,b;
    for(int i=left+1;i<right;i++){
        a.push_back(aa[i]);
        b.push_back(bb[i]);
    }
    n = a.size();

    int ans = INT_MAX;

    int l = -1, r = n;
    int lm = -1, rm = n;
    for(int i=0;i<n;i++){
        int x = b[i];
        int flag = 0;
        for(int j=l+1;j<n;j++){
            if(a[j] == x){
                flag = 1;
                l = j;
                break;
            }
        }
        if(flag == 0){
            break;
        }
        lm = i;
    }

    for(int i=n-1;i>lm;i--){
        int x = b[i];
        int flag = 0;
        for(int j=r-1;j>l;j--){
            if(a[j] == x){
                flag = 1;
                r = j;
                break;
            }
        }
        if(flag == 0){
            break;
        }
        rm = i;
    }

    // cout << l << " " << r << endl;
    // cout << lm << " " << rm << endl;
    int res = 0;
    
    if(rm == lm+1){
        res = 0;
    } else if(lm != -1 and rm != n){
        res = rm - lm - 1;
    } else if(lm != -1){
        res = n-1 - lm;
    } else if(rm != n){
        res = rm;
    } else {
        res = n;
    }

    ans = min(res, ans);
    // cout << res << endl;

    l = -1, r = n;
    lm = -1, rm = n;
    

    for(int i=n-1;i>=0;i--){
        int x = b[i];
        int flag = 0;
        for(int j=r-1;j>=0;j--){
            if(a[j] == x){
                flag = 1;
                r = j;
                break;
            }
        }
        if(flag == 0){
            break;
        }
        rm = i;
    }

    for(int i=0;i<rm;i++){
        int x = b[i];
        int flag = 0;
        for(int j=l+1;j<r;j++){
            if(a[j] == x){
                flag = 1;
                l = j;
                break;
            }
        }
        if(flag == 0){
            break;
        }
        lm = i;
    }

    if(lm == rm-1){
        res = 0;
    } else if(lm != -1 and rm != n){
        res = rm - lm - 1;
    } else if(lm != -1){
        res = n-1 - lm;
    } else if(rm != n){
        res = rm;
    } else {
        res = n;
    }

    ans = min(ans, res);


    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ": ";
        solve();
    }
}