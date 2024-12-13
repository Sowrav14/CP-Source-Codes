#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

char ques[110][5];
char ans[N];

void solve(){

    int n, k; cin >> n >> k;
    for(int i=1;i<=n;i++){
        ans[i] = 'X';
        for(int j=0;j<5;j++){
            ques[i][j] = 'X';
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            char op, val; cin >> op >> val;
            if(ques[j][op - 'A'] == 'X'){
                if(val == 'T') ques[j][op - 'A'] = 'T';
                else ques[j][op - 'A'] = 'F';
            } else if(ques[j][op - 'A'] != val){
                ans[j] = '?';
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(ans[i] != 'X') continue;
        set<char>t, f;
        // cout << i << endl;
        for(int j=0;j<4;j++){
            // cout << ques[i][j] << " ";
            if(ques[i][j] == 'T') t.insert((char)(j+'A'));
            else if(ques[i][j] == 'F') f.insert((char)(j+'A'));
        }
        // cout << f.size() <<  endl;
        if(t.size() == 1){
            ans[i] = *t.begin();
            // cout << ans[i] <<endl;
            continue;
        } else if(t.size() > 1){
            ans[i] = '?';
        } else if(f.size() == 3){
            // cout << "HERE" << endl;
            if(f.count('A') == 0) ans[i] = 'A';
            if(f.count('B') == 0) ans[i] = 'B';
            if(f.count('C') == 0) ans[i] = 'C';
            if(f.count('D') == 0) ans[i] = 'D';
        } else{
            ans[i] = '?';
        }


    }
    for(int i=1;i<=n;i++) cout << ans[i] << " \n"[i == n];

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