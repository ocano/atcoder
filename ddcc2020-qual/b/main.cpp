#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define rep3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define rep_r(i, n) for (int i = (int)(n) - 1; (i) >= 0; --(i))
#define rep3r(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); --(i))
#define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;
#define INF ((1LL << 62) - (1LL << 31))

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // constexpr char endl = '\n';

    int N;
    cin >> N;
    std::vector<int> v(N);
    rep(i, N) {
        cin >> v[i];
    }

    std::vector<ll> sum(N);
    std::vector<ll> rsum(N);

    sum[0] = v[0];
    rep3(i, 1, N) {
        sum[i] = sum[i - 1] + v[i];
    }

    ll ans = INF;
    rep(i, N - 1) {
        chmin(ans, abs((sum[N - 1] - sum[i]) - sum[i]));
    }

    cout << ans << '\n';
}
