#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    int cnt = 0;
    string s; cin >> s;
    for(int i=0;i<n;i++) if(s[i] == 'o') cnt++;
    for(int i=0;i<n;i++){
        if(s[i] != '?') continue;
        if(i-1>=0 and s[i-1] == 'o') s[i] = '.';
        if(i+1<n and s[i+1] == 'o') s[i] = '.';
    }
    // cout << s << endl;
    int req = k - cnt;
    int avail = 0;
    for(int i=0;i<n;i++) if(s[i] == '?') avail++;
    if(req == 0){
        for(int i=0;i<n;i++){
            if(s[i] == '?') s[i] = '.';
        }
    } else {
        int mx = 0, cluster = 0;;
        for(int i=0;i<n;i++){
            if(s[i] == '?'){
                int c = 0;
                int j = i;
                while(j<n and s[j] == '?') j++, c++;
                i = j;
                if(c%2 == 0) mx += N;
                else mx += (c+1)/2;

                if(c%2 and c>1) cluster++;
            }
        }
        // cout << mx << " " << req << endl;
        if(mx == req){
            int flag = 0;
            for(int i=0;i<n;i++){
                if(s[i] != '?'){
                    flag = 0;
                    continue;
                }
                if(!flag) s[i] = 'o';
                else s[i] = '.';
                flag = 1 - flag;
            }
        } else if(mx-req==cluster){
            for(int i=0;i<n;i++){
                if(s[i] == '?'){
                    int c = 0;
                    int j = i;
                    while(j<n and s[j] == '?') j++, c++;
                    if(c%2 == 0){
                        i = j;
                        continue;
                    }   

                    if(c == 1){
                        s[i] = 'o';
                    } else {
                        for(int it=i;it<j;it+=2){
                            s[it] = '.';
                            s[it+1] = 'o';
                        }
                    }
                    i = j;
                }
            }
        }
    }

    cout << s << endl;

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