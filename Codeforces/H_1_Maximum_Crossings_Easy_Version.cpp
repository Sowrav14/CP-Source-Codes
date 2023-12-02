#include<bits/stdc++.h>
using namespace std;

#define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n)              for(int i=0;i<n;i++)
#define f1(i,n)             for(int i=1;i<=n;i++)
#define rf(i,n)             for(int i=n-1;i>=0;i--)
#define rf1(i,n)            for(int i = n;i>=1;i--)
#define saisir(v,x)         int x; cin>>x; v.push_back(x);
#define le_debut            signed main
#define int                 long long int
#define endl                '\n'
#define pb                  push_back
#define un                  first
#define deux                second
#define oui                 cout << "YES" << endl
#define non                 cout << "NO" << endl
#define homme               cout << "Bob" << endl
#define femme               cout << "Alice" << endl
#define un_de_minus         cout << "-1" << endl
#define duck                cout << 0 << endl;
#define reponse             cout << ans << endl
#define ici                 cout << "Je suis ici" << endl
const int N = 2*1e5+10;
const int M = 1e9+7;


// Inline Function
inline int bigmod(int x,int y)  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline int ad(int x,int y)      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline int sub(int x,int y)     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline int gun(int x,int y)     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}

int n;
vector<int>a;


// Merge sort and counting inversion in O(nlog(n))
int inversions;


void merge(vector<int>&array, int l, int m, int r) {
    int i, j, k, nl, nr;
    // size of left and right sub-arrays
    nl = m-l+1; nr = r-m;
    vector<int> larr(nl), rarr(nr);

    //fill left and right sub-arrays

    for(i = 0; i<nl; i++){
        larr[i] = array[l+i];
    }
    for(j = 0; j<nr; j++){
        rarr[j] = array[m+1+j];
    }
    
    i = 0; j = 0; k = l;
    //marge temp arrays to real array
    while(i < nl && j<nr) {
        if(larr[i] < rarr[j]) {
            array[k] = larr[i];
            i++;
        }else{
            // cout << larr[i] << " " << rarr[i] << endl;
            inversions += nl - i;
            array[k] = rarr[j];
            j++;
        }
        k++;
    }

    while(i<nl) {       //extra element in left array
        array[k] = larr[i];
        i++; k++;
    }

    while(j<nr) {     //extra element in right array
        array[k] = rarr[j];
        j++; k++;
    }

}


void mergeSort(vector<int>&array, int l, int r) {
    int m;
    if(l < r) {
        int m = l+(r-l)/2;
        // divide the array into two then in merge them sorted order
        mergeSort(array, l, m);
        mergeSort(array, m+1, r);
        merge(array, l, m, r);
    }
}



void allons_y(){

    cin >> n;
    a.clear();
    f(i,n){
        int x; cin >> x;
        a.pb(x);
    }
    inversions = 0;
    mergeSort(a, 0, n-1);

    cout << inversions << endl;

   
}


le_debut(){
    Sowrav_Nath
    int test;
    // test = 1;
    cin >> test;
    f1(tc,test){
        // cout << "Case " << tc << ": ";
        // memset(dp,0,sizeof(dp));
        allons_y();
    }
}
