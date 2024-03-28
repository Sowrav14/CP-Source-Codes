#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int i = 0, j = n-1;
    int prev = 0;
    string ans = "";
    while(i<=j){
        if(v[i] < v[j]){
            if(v[i] > prev){
                ans += "L";
                prev = v[i];
                i++;
            } else if(v[j] > prev){
                ans += 'R';
                prev = v[j];
                j--;
            } else{
                break;
            }
        } else if(v[j] < v[i]) {
            if(v[j] > prev){
                ans += "R";
                prev = v[j];
                j--;
            } else if(v[i] > prev){
                ans += "L";
                prev = v[i];
                i++;
            } else {
                break;
            }
        } else{
            int l = i, r = j, lst = prev;
            // take left....
            string res1 = "";
            while(i <= j){
                if(v[i] > prev){
                    res1 += "L";
                    prev = v[i];
                    i++;
                } else{
                    break;
                }
            }

            // take right....
            string res2 = "";
            while(r >= l){
                if(v[r] > lst){
                    res2 += "R";
                    lst = v[r];
                    r--;
                } else{
                    break;
                }
            }
            // cout << res1 << " and " << res2 << endl; 
            if(res1.size() > res2.size()){
                ans += res1;
            } else {
                ans += res2;
            }
            break;
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;

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