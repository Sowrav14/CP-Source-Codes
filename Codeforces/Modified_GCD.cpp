#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class nums{
public:
    int x;
    set<int>dx;
    nums(){}
    nums(int x){
        this->x = x;
        for(int i=1;i*i<=x;i++){
            if(x%i == 0){
                dx.insert(i);
                dx.insert(x/i);
            }
        }
    }
};

void solve(){

     int a,b; cin >> a >> b;

    nums na = nums(a);
    nums nb = nums(b);
    vector<int>divisors;
    set_intersection(na.dx.begin(), na.dx.end(), nb.dx.begin(), nb.dx.end(), inserter(divisors, divisors.begin()));

    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        int li = lower_bound(divisors.begin(), divisors.end(), l) - divisors.begin();
        int ri = upper_bound(divisors.begin(), divisors.end(), r) - divisors.begin() - 1;

        if(li > ri or ri == divisors.size()){
            cout << -1 << endl;
        } else{
            cout << divisors[ri] << endl;
        }
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