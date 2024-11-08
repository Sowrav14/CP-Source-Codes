#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
const double PI = acos(-1);

/*
	- represent complex number.
*/
struct base {
	double a, b;
	base(double a = 0, double b = 0) : a(a), b(b) {}
	const base operator + (const base &c) const
		{ return base(a + c.a, b + c.b); }
	const base operator - (const base &c) const
		{ return base(a - c.a, b - c.b); }
	const base operator * (const base &c) const
		{ return base(a * c.a - b * c.b, a * c.b + b * c.a); }
};

/* 
	- Fast Fourier Transform of p if inv = 0 
	- Inverse FFT of p if inv = 1
	- all transformation are inplace
*/
void fft(vector<base> &p, bool inv = 0) {
	int n = p.size(), i = 0;
	for(int j = 1; j < n - 1; ++j) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1);
			if(j < i) swap(p[i], p[j]);
	}
	for(int l = 1, m; (m = l << 1) <= n; l <<= 1) {
		double ang = 2 * PI / m;
		base wn = base(cos(ang), (inv ? 1. : -1.) * sin(ang)), w;
		for(int i = 0, j, k; i < n; i += m) {
			for(w = base(1, 0), j = i, k = i + l; j < k; ++j, w = w * wn) {
				base t = w * p[j + l];
				p[j + l] = p[j] - t;
				p[j] = p[j] + t;
			}
		}
	}
	if(inv) for(int i = 0; i < n; ++i) p[i].a /= n, p[i].b /= n;
}

/*
	Return C(x) = A(x) * B(x)
	Use FFT and Inverse FFT 
*/
vector<long long> multiply(vector<int> &a, vector<int> &b) {
	int n = a.size(), m = b.size(), t = n + m - 1, sz = 1;
	while(sz < t) sz <<= 1;
	vector<base> x(sz), y(sz), z(sz);
	for(int i = 0 ; i < sz; ++i) {
		x[i] = i < (int)a.size() ? base(a[i], 0) : base(0, 0);
		y[i] = i < (int)b.size() ? base(b[i], 0) : base(0, 0);
	}
	fft(x), fft(y);
	for(int i = 0; i < sz; ++i) z[i] = x[i] * y[i];
	fft(z, 1);
	vector<long long> ret(sz);
	for(int i = 0; i < sz; ++i) ret[i] = (long long) round(z[i].a);
	while((int)ret.size() > 1 && ret.back() == 0) ret.pop_back();	// what you need?
	return ret;
}

/*  DSU  */
int br[500005], par[500005];
int get(int x){
 	return (par[x] == x ? x : par[x] = get(par[x]));
}
void link(int x, int y){
 	x = get(x);
 	y = get(y);
 	par[x] = y;
}

/*
    store all convolution of character a in s and b in t
*/
vector<int> con[6][6];
string s,t;
int n, m;

void compute_convolutions(){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            vector<int>a, b;
            for(int k=0;k<n;k++) a.push_back((s[k]-'a') == i);
            for(int k=0;k<m;k++) b.push_back((t[k] - 'a') == j);
            con[i][j] = multiply(a, b);
        }
    }
}

/* 
    Return the answer to the query considering ending of s in position x 
*/
int query(int x){
    int ans = 6;
    for(int i=0;i<6;i++) par[i] = i, br[i] = 0;

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(con[i][j].size() > x and con[i][j][x] > 0){
                link(i, j);
            }
        }
    }

    for(int i=0;i<6;i++) br[get(i)] = 1;
    for(int i=0;i<6;i++) ans -= br[i];

    return ans;
}

void solve(){

    cin >> s >> t;
    n = s.size(); m = t.size();
    reverse(t.begin(), t.end());

    compute_convolutions();

    for(int i=m-1;i<n;i++){
        cout << query(i) << " ";
    } cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}