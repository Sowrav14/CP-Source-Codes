#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double eps = 1e-8;
int n,k;
double l, r, m, sum, temp;
vector<int>a;


void solve(){

    cin >> n >> k;
    a.resize(n, 0);
    sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    l = a.front(), r = a.back();
    while(l + eps <= r){
		m = (l + r) / 2;
		temp = 0;
		for(int i=0;i<n;++i) if(a[i] > m) temp += a[i] - m;
		if((sum - n * m) == k * temp / 100){
			r = m;
			break;
		}
		if((sum - n * m) > k * temp / 100) l = m;
		else r = m;
	}

    cout << fixed << setprecision(10) << r << endl;

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