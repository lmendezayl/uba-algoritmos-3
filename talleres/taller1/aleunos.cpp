#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// podria intentar usar el bitset... 
void crear_bitset(int n, vector<bool>& seq01, ll l, ll r){
    // complejidad: a = 2, c = 2 -- teo maestro -->  T(n) = O(n log n) i
    if (l == r){
        seq01[l] = n%2;
        return;
    }
    ll medio = (l + r) / 2;
    seq01[medio] = n%2;
    crear_bitset(n/2, seq01, l, medio-1);
    crear_bitset(n/2, seq01, medio+1, r);
}

int calcular_unos(int n, ll l, ll r){
    ll p = ceil(log2(n+1));
    ll k = (1 << p) - 1; // 2^(ceil(log_2(n))) - 1
    //if (l == 1  && r == k) return n; // caso que pida todo el bitset 
    cout << p << " " << k << endl;
    vector<bool> seq01(k, 0); // vector de ceros y unos
    crear_bitset(n, seq01, l-1, r-1);
    int res = 0;
    for (bool b : seq01) if (b) res++;
    return res;
}

int main(){
    ll n, l, r;
    cin >> n >> l >> r;
    cout << calcular_unos(n, l, r) << "\n";
    return 0;
}
