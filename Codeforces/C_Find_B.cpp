    #include<bits/stdc++.h>
    using namespace std;
    #define int long long int
    #define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    void solve(){

        int n, q; cin >> n >> q;
        vector<int>v(n+10, 0), pref(n+10, 0), ones(n+10, 0);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] == 1) ones[i] = 1;

            pref[i] = pref[i-1] + v[i];
            ones[i] = ones[i-1] + ones[i];
        }

        // for(int i=1;i<=n;i++) cout << pref[i] << " "; cout << endl;
        // for(int i=1;i<=n;i++) cout << ones[i] << " "; cout << endl;

        while(q--){
            int l,r; cin >> l >> r;
            if(l == r){
                cout << "NO" << endl;
                continue;
            }
            int one = ones[r] - ones[l-1];
            int sum = pref[r] - pref[l-1];
            int extra = sum - (r - l + 1);

            if(extra >= one) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

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