#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define rep3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define rep_r(i, n) for (int i = (int)(n) - 1; (i) >= 0; --(i))
#define rep3r(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); --(i))
#define all(x) std::begin(x), std::end(x)
#define endl '\n';
using namespace std;
using ll = long long;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << p.first << " " << p.second;
}
template <typename T_container,
          typename T = typename enable_if<!is_same<T_container, string>::value,
                                          typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    string sep = "";
    for (const T &x : v) os << sep << x, sep = " ";
    os << '\n';
    return os;
}
#define INF ((1LL << 62) - (1LL << 31))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // constexpr char endl = '\n';

    int H, W, K;
    cin >> H >> W >> K;
    std::vector<std::vector<char>> v;
    std::vector<std::vector<int>> data(H, std::vector<int>(W));
    char n;
    rep(i, H) {
        rep(j, W) {
            cin >> n;
            if (n == '.') {
                data[i][j] = 0;
            } else if (n == '#') {
                data[i][j] = K--;
            }
        };
    }

    rep(i, H) {
        rep3(j, 1, W) {
            if (data[i][j] == 0 && data[i][j - 1] != 0) {
                data[i][j] = data[i][j - 1];
            }
        };
    }
    rep(i, H) {
        rep3r(j, 1, W) {
            if (data[i][j] != 0 && data[i][j - 1] == 0) {
                data[i][j - 1] = data[i][j];
            }
        };
    }
    rep3(i, 1, H) {
        if (data[i - 1][0] != 0 && data[i][0] == 0) {
            rep(j, W) data[i][j] = data[i - 1][j];
        }
    }

    rep_r(i, H - 1) {
        if (data[i + 1][0] != 0 && data[i][0] == 0) {
            rep(j, W) data[i][j] = data[i + 1][j];
        }
    }
    cout << data << endl;
}
