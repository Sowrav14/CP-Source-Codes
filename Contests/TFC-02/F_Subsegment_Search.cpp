#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


struct KMP {
	int n;
	vector<int> p;
	vector<int> pi;
	KMP(const vector<int> &x) {
		n = x.size();
		p = x;
		pi.assign(n, -1);
	}
	void prefix_function(){
		for(int i=1,now=-1;i<n;i++){
			while(now != -1 && p[now+1] != p[i]) now = pi[now];
			if(p[now+1] == p[i]) now++;
			pi[i] = now;
		}
		//only when p=pattern+#+text type
		for(int &x: pi) x++;
	}
};


void solve(){
	int n, m; cin >> n >> m;
	
	vector<int> a(n);
	for(int &x: a) cin >> x;
	
	vector<int> b(m);
	for(int &x: b) cin >> x;
	
	vector<int> c;
	for(int i=1;i<m;i++) c.push_back(b[i] - b[i-1]);
	c.push_back(INT_MAX);
	for(int i=1;i<n;i++) c.push_back(a[i] - a[i-1]);
	
	KMP kmp(c);
	kmp.prefix_function();
	
	int ans = 0;
	for(int x : kmp.pi) if(x == m - 1) ans++;
	cout << ans << endl;

}		

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int testcase=1;
	//cin>>testcase;
	for(int i=1;i<=testcase;i++){
		//cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}