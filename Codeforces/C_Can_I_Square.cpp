#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

void solve(){

	ll n; cin >> n;
	ll sum = 0;
	for(int i=0;i<n;i++){
		ll x; cin >> x;
		sum += x;
	}

	ll temp = sqrtl(sum);
	if(temp * temp * 1ll == sum) cout << "YES" << endl;
	else cout << "NO" << endl;

}


int main(){
	int t; cin >> t;
	for(int i=1;i<=t;i++){
		// cout << "Case " << t << ": ";
		solve();
	}
}