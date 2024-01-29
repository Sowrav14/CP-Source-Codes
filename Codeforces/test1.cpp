#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int r,c,n; cin >> r >> c >> n;
    vector<pair<int,int>>p;
    vector<int>v;

    for(int i=1;i<=n;i++){
        int x,y,w; cin >> x >> y >> w;
        pair<int,int>temp = {x,y};
        int it = upper_bound(p.begin(), p.end(), temp) - p.begin();
        if(it == p.size()){
            p.push_back(temp);
            v.push_back(w);
        } else{
            if(p[it].second > temp.second and w > v[it]){
                p[it] = temp;
                v[it] = w;
            }
        }
    }
    int sum = 0;
    for(auto i : v){
        sum += i;
    }
    cout << sum << endl;

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