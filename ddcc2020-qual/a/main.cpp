#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define rep_r(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define rep3r(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define all(x) std::begin(x), std::end(x)
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    int X, Y;
    cin >> X >> Y;
    
    int ans = 0;

    if (X == 1) {
        ans += 300000;
    } else if (X == 2 ) {
        ans += 200000;
    } else if (X == 3 ) {
        ans += 100000;
    }
    if (Y == 1) {
        ans += 300000;
    } else if (Y == 2 ) {
        ans += 200000;
    } else if (Y == 3 ) {
        ans += 100000;
    }

    if (X == 1 && Y== 1) {
        ans += 400000;
    }

    cout << ans << '\n';
}

