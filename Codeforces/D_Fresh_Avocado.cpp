#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
const double eps = 1e-15;

void solve(){

    double n, r; cin >> n >> r;

    for(int i=1;i<=n;i++){
        double a, b, c; cin >> a >> b >> c;
        double x1, x2, y1, y2;
        
        if(b == 0){
            x1 = -c; x2 = -c;
            y1 = sqrt(r * r - c * c);
            y2 = -sqrt(r * r - c * c);
        } else if(a == 0){
            y1 = -c; y2 = -c;
            x1 = sqrt(r * r - c* c);
            x2 = -sqrt(r * r - c * c);
        }else{
            a += eps, b += eps, c += eps;
            double A = b * b + a * a;
            double B = 2 * a * c;
            double C = c * c - b * b * r * r;

            x1 = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
            x2 = (-B - sqrt(B * B - 4 * A * C)) / (2 * A);

            y1 = ((-a * x2) - c) / b;
            y2 = ((-a * x1) - c) / b;
        }
        cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
        double area = abs(0.5 * (x1 * y2 - x2 * y1));
        double cone = asin((2 * area) / (r * r));
        double kola = 0.5 * cone * r * r;
        cout << area << " " << cone << "  " << kola << endl;
        double total = acos(-1) * r * r;
        double one = area == 0 ? total / 2 : kola - area;
        double two = total - one;
        cout << total << " " << one << " " << two << endl;
        cout << (one/total) << " " << (two/total) << endl;
        
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