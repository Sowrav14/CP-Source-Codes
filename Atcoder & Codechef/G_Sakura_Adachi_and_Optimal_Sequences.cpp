#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e6 + 3;
const int M = 1e6 + 3;
const int inf = 1e12;

int f[N],invf[N];


// Big Mod
int A_pow_B(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (1ll * ret%M * a%M) % M;
        }
        a = (1ll * a%M * a%M) % M;
        b >>= 1;
    }
    return ret;
}



// Calculating factorials and inverse factorial
void fact_invfact(){
    f[0] = 1;
    for(int i=1;i<N;i++){
        f[i] = (1ll * f[i-1]%M * i%M) % M;
    }

    // calculate fact inverse
    invf[N-1] = A_pow_B(f[N-1],M-2);
    for(int i=N-2;i>=0;i--){
        invf[i] = (1ll * invf[i+1]%M * (i+1)%M) % M;
    }
}


// Calculating nCr
int nCr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n]%M * invf[n-r]%M * invf[r]%M) % M ; 
}


// Calculating nPr
int nPr(int n, int r){
    if(n < 0 or n < r) return 0;
    return (1ll * f[n]%M * invf[n-r]%M) % M;
}

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for(int i=0;i<n;i++){
    cin >> b[i];
  }

  int tot = 0;
  int ans = 1;
  while(1){
    vector<int> temp;
    for(int i=0;i<n;i++){
      temp.push_back(b[i] / 2);
    }
    bool flag = 1;
    for(int i=0;i<n;i++){
      if(temp[i] < a[i]){
        flag = 0;
        break;
      }
    }

    if(flag){
      tot++;
      int sum = 0;
      int res = 1;
      for(int i=0;i<n;i++){
        int x = (b[i] - temp[i] * 2ll);
        sum += x;
        res = (res%M * invf[x]%M) % M;
      }
      tot += sum;
      // sum %= M;
      // cout << sum << " " << res << endl;
      res = sum > N ? 0 : (res%M * f[sum]%M) % M;
      ans = (ans%M * res%M) % M;
      b = temp;
    } else {
      int sum = 0;
      int res = 1;
      for(int i=0;i<n;i++){
        int x = (b[i] - a[i]);
        sum += x;
        // cout << x << " " << invf[x] << endl;
        res = (res%M * invf[x]%M) % M;
      }
      tot += sum;
      // sum %= M;
      // cout << sum << " " << res << endl;
      res = sum > N ? 0 : (res%M * f[sum]%M) % M;
      // cout << res << endl;
      ans = (ans%M * res%M) % M;
      break;
    }
  }
  cout << tot << " " << ans << endl;

}


signed main(){
  Fast_IO()
  fact_invfact();
  int t = 1;
  cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}