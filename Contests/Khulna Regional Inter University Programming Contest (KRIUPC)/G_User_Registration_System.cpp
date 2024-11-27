#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Listing{
    set<int>fp;
    int mx = 0;
};

void solve(){

    int n; cin >> n;
    map<string, Listing>m;
    while(n--){
        char t; cin >> t;
        string s; cin >> s;
        if(t == 'a'){
            if(m.count(s) == 0){
                cout << "OK" << endl;
                Listing l;
                l.mx = 1;
                m[s] = l;
            } else{
                if(m[s].fp.size() == 0){
                    cout << s << m[s].mx << endl;
                    m[s].mx += 1;
                } else {
                    int x = *m[s].fp.begin();
                    if(x == 0){
                        cout << "OK" << endl;
                    } else {
                        cout << s << x << endl;
                    }
                    m[s].fp.erase(x);
                }
            }
        } else{
            bool del = false;
            for(int i=s.size();i>0;i--){
                string fst = s.substr(0, i);
                string lst = s.substr(i, s.size() - i);
                bool flag = true;
                for(int i=0;i<lst.size();i++){
                    if(!isdigit(lst[i])){
                        flag = false;
                    }
                }
                if(lst.size() == 0){
                    lst = "0";
                }
                if(flag == false){
                    continue;
                }
                // cout << lst << endl;
                int x = stoll(lst);

                if(m.count(fst) == 0){
                    continue;
                } else if(x == 0){
                    cout << "DELETED" << endl;
                    m[fst].fp.insert(0);
                    del = true;
                    break;
                }

                if(m[fst].mx <= x){
                    continue;
                }

                if(m[fst].fp.find(x) != m[fst].fp.end()){
                    continue;
                }
                del = true;
                cout << "DELETED" << endl;
                m[fst].fp.insert(x);
            }
            if(!del){
                cout << "INVALID" << endl;
            }
        }
    }

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