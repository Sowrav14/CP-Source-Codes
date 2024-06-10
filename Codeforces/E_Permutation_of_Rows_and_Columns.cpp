#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<vector<int>>v, w;
int n,m;
bool isvalid(){
    int tot = n * m;
    vector<int> row(tot+10, 0);
    vector<int> vis(n, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            row[v[i][j]] = i;
        }
    }
    // cout << w[0][0] << endl;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int r = row[w[i][0]];
        // cout << w[i][0] << " " << r << endl;
        if(vis[r] == 1) continue;
        vector<int>a,b;
        for(int j=0;j<m;j++){
            a.push_back(v[r][j]);
            b.push_back(w[i][j]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // cout << endl;
        // for(int k=0;k<m;k++) cout << a[k] << " "; cout << endl;
        // for(int k=0;k<m;k++) cout << b[k] << " "; cout << endl;
        // cout << endl;

        for(int j=0;j<m;j++){
            if(a[j] != b[j]){
                // cout << i << "  " << r << endl;
                
                return 0;   
            }
        }
        vis[r] = 1;
        cnt++;
    }

    return (cnt == n ? 1 : 0);
}

bool transpose(){
    int tot = n * m;
    vector<int> col(tot+10, 0);
    vector<int> vis(m, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            col[v[i][j]] = j;
        }
    }
    // cout << w[0][0] << endl;
    int cnt = 0;
    for(int i=0;i<m;i++){
        int c = col[w[0][i]];
        // cout << w[0][i] << " " << c << endl;
        if(vis[c] == 1) continue;
        vector<int>a,b;
        for(int j=0;j<n;j++){
            a.push_back(w[j][i]);
            b.push_back(v[j][c]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // cout << endl;
        // for(int k=0;k<m;k++) cout << a[k] << " "; cout << endl;
        // for(int k=0;k<m;k++) cout << b[k] << " "; cout << endl;
        // cout << endl;

        for(int j=0;j<n;j++){
            if(a[j] != b[j]){
                // cout << i << "  " << c << endl;
                
                return 0;   
            }
        }
        vis[c] = 1;
        cnt++;
    }

    return (cnt == m ? 1 : 0);
}

void solve(){

    cin >> n >> m;
    v.clear(); w.clear();
    for(int i=0;i<n;i++){
        vector<int>t;
        for(int j=0;j<m;j++){
            int x; cin >> x;
            t.push_back(x);
        }
        v.push_back(t);
    }
    for(int i=0;i<n;i++){
        vector<int>t;
        for(int j=0;j<m;j++){
            int x; cin >> x;
            t.push_back(x);
        }
        w.push_back(t);
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << w[i][j] << " ";
    //     } cout << endl;
    // }

    int ans = isvalid();
    // cout << ans << endl;
    ans &= transpose();

    cout << (ans ? "YES" : "NO") << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}