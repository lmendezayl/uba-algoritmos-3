#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll len(ll n) {
    if (n <= 1) return 1;
    return 2 * len(n/2) + 1;
}

ll calcular_unos(ll n, ll l, ll r, ll maxl, ll maxr) {
    if (n == 0) return 0;
    if (n == 1) {
        if (maxl <= l && r <= maxr) return 1;
        else return 0;
    }
    ll mid = l + (len(n/2));
    ll res = 0;
    if (maxl <= mid - 1) res += calcular_unos(n / 2, l, mid - 1, maxl, maxr);
    if (maxl <= mid && mid <= maxr) res += n % 2; 
    if (mid + 1 <= maxr) res += calcular_unos(n / 2, mid + 1, r, maxl, maxr);
    return res;
}

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    // 1LL == (ll)1 tengo q hacerlo long long sino type(k) = int
    ll k = len(n);
    cout << calcular_unos(n, 1, k, l, r) << "\n";
    return 0;
}

