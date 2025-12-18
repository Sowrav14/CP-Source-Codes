#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 100 + 10;
const int M = 1e6;
const int inf = 1e12;

int n;
double p[N];

void solve(){

  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> p[i];
  }
  sort(p+1,p+n+1,greater<double>());
  double ans = 0.0;
  double pro = 1.0;
  for(int i=1;i<=n;i++){
    double res = ans * (1.0 - p[i]) + pro * p[i];
    pro *= (1.0 - p[i]);
    ans = max(ans, res);
  }
  cout << fixed << setprecision(12) << ans << endl;

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