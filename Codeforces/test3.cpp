#include<bits/stdc++.h>
using namespace std;
int prod(int n){
 int res=1;
 while(n){
  res*=n%10;
  n/=10;
 }
 return res;
}
int main(){
 int x,y,c=0;
 cin>>x>>y;
 for(int i=1;i<=x;i++){
  if(prod(i)<=y)c++;
 }
 cout<<c;
}
