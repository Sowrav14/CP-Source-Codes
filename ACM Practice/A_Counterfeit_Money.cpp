#include <iostream>
#include <string>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  string s; cin >> s;
  int n = s.size();
  int sum = 0, sg = 1;
  for(int i=n-1;i>=0;i--){
    if(i-2 >= 0){
      int num = (s[i]-'0') + (s[i-1]-'0')*10 + (s[i-2]-'0')*100;
      sum += sg * num;
      sg *= -1;
      i -= 2;
    } else if(i-1 >= 0){
      int num = (s[i]-'0') + (s[i-1]-'0')*10;
      sum += sg * num;
      sg *= -1;
      i -= 1;
    } else {
      int num = (s[i]-'0');
      sum += sg * num;
      sg *= -1;
    }
  }
  cout << abs(sum) << " " << ( (((sum % 13) + 13) % 13) == 0 ? "YES" : "NO") << endl;

}


signed main(){
  Fast_IO()
  int t = 1;
  cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}