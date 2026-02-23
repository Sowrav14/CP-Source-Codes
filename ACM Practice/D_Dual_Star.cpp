#include<bits/stdc++.h>

using namespace std;
// #define int double

const double eps = 1e-12;

void GG() {
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;

    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;

    double r, w; cin >> r >> w;

    double cx, cy, cz;
    cx = (x1 + x2) / 2.0;
    cy = (y1 + y2) / 2.0;
    cz = (z1 + z2) / 2.0;

    double d =  sqrt(1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2) + 1ll * (z1 - z2) * (z1 - z2)) / 2.0;

    double thetac = asin(r / d);

    double xx = (1ll * (0 - cx) * (x1 - cx) + 1ll * (0 - cy) * (y1 - cy) + 1ll * (0 - cz) * (z1 - cz)) / (sqrt(1ll * cx * cx + 1ll * cy * cy + 1ll * cz * cz) * sqrt(1ll * (x1 - cx) * (x1 - cx) + 1ll * (y1 - cy) * (y1 - cy) + 1ll * (z1 - cz) * (z1 - cz)));
    // cout << "hellko " << xx << '\n';
    if(xx > 0) xx -= eps;
    else xx += eps;
    double theta1 = acos(xx);
    double theta2 = acos(-1) - theta1;
    // cout << acos(1) << ' ' << acos((int)xx) << ' ' << xx << '\n';
    double theta1p = theta1 - thetac;
    double theta2p = theta2 - thetac;

    double t = min(theta1p / w, theta2p / w);
    // cout << "YO\n";
    // cout << theta1 << ' ' << theta2 << ' ' << thetac << '\n';
    if (thetac - theta1 >= eps or thetac - theta2 >= eps) {
        cout << 0 << '\n';
    } else {
        cout << fixed << setprecision(10) <<t << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttc = 1;
    cin >> ttc;
    while(ttc--) {
      GG();
    }
}