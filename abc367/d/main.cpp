/* {{{ */
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
    string sep = "\t";
    for (const T &x : v) os << sep << x;
    return os;
}
#define INF ((1LL << 62) - (1LL << 31))
/* }}} */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll ans = 0;
    cin >> N >> M;
    std::vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    std::vector<int> sum_mod(2 * N);
    std::vector<int> count(M, 0);

    rep(i, 2 * N) {
        if (i == 0) {
            sum_mod[0] = A[0] % M;
        } else {
            sum_mod[i] = (sum_mod[i - 1] + A[i % N]) % M;
        }
    }

    /* cerr << sum_mod << "\n"; */

    rep(i, N) {
        count[sum_mod[i]]++;
    }

    /* cerr << count << "\n"; */

    rep3(i, N, 2 * N) {
        count[sum_mod[i - N]]--;
        /* cerr << count[sum_mod[i]] << "\n"; */
        ans += count[sum_mod[i]];
        count[sum_mod[i]]++;
    }

    cout << ans << '\n';
}
