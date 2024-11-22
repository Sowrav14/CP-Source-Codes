#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int again(vector<int>v,int i){

    int sum=0;
    int mul=1;
    for(int k=0;k<=i;k++) sum+=v[k],mul*=v[k];

    return (mul&sum);
}

void check(vector<int>v){

    bool f=1;
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(i==j){
                continue;
            }
            else{
                if(again(v,i)==again(v,j)) f&=0;
            }
        }
    }
    if((*max_element(v.begin(),v.end())-*min_element(v.begin(),v.end()))>10) f=0;

    if(f){
        for(auto u:v) cout << u << " ";
        cout << endl;
    }

}
int n;
void func(vector<int>v){

    if(v.size()==n){
         check(v);
         return;
    }

    for(int i=2;i<=3*n;i++){
        v.push_back(i);
        func(v);
        v.pop_back();
    }


}


void solve(){

    cin >> n;
    vector<int>v;
    func(v) ;

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