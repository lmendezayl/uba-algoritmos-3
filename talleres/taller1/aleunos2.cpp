#include <bits/stdc++.h>
using namespace std;

vector<int> f(int n, vector<int> seq = {}) {
    if (seq.empty()) {
        seq = {n/2, n%2, n/2};
    }
    for (int e : seq) {
        if (e == 0 || e == 1) return seq;
        else {
            vector<int> left = f(e);
            vector<int> right = f(e);
            reverse(right.begin(), right.end());
            vector<int> res;
            res.reserve(left.size() + 1 + right.size());
            res.insert(res.end(), left.begin(), left.end());
            res.push_back(seq[1]);
            res.insert(res.end(), right.begin(), right.end());
            return res;
        }
    }
    return {};
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> seq = f(n);
    int sumRes = 0;
    for (int i = l-1; i < r; i++) sumRes += seq[i];
    cout << sumRes << "\n";
    return 0;
}

