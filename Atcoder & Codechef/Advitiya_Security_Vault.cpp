#include<bits/stdc++.h>
#define int long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
using namespace std;
const int mod = 1e9+7;

int binexp(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (1ll * ret%mod * a%mod) % mod;
        }
        a = (1ll * a%mod * a%mod) % mod;
        b >>= 1;
    }
    return ret;
}

void do_the_honour(int tt){
	
	int n,k;cin >> n >>k;
	
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	int i=0,j=n-1;
	int num=1;
	while(i<j){
		if(a[i]==0 and a[j]==0) num=(num*k)%mod;
		else if(a[i]!=a[j] and a[i]!=0 and a[j]!=0) num=0;
        i++; j--;
		}
		
		if(n%2 and a[i]==0) num=(num*k)%mod; 
		int pal=num;
        int x= count(a,a+n,0);
        int total=binexp(k,x);
        int non=(total-pal+mod)%mod;
        int aa=((non)%mod+(pal)%mod)%mod;
        cout << aa << endl;
	
	


}



signed main(){
	
	int t=1;
	cin>>t;
	for(int i=0;i<t;i++){
		
		do_the_honour(i+1);
		
		}
	return 0;
	}