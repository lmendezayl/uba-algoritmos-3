#include <bits/stdc++.h>
using namespace std;
/*
 * Notas de cosas que aprendi con este taller
 * - no puedo crear variables en llamadas de funciones
 *   convertivilidad(x, y, set<int> seq ) esta MAL
 * - set::insert devuelve un par (iterador, bool)
 *
 * - usar set esta op si no tengo repetidos y tengo de invariante seq[x] < seq[x+1]
 * 
 * update:
 *
 * - no pasa el test 7 y tira 58 mb de espacio xd
 *   vamos a NO Hacer copias y vamos a pasar un vector y simplemente modficarlo 
 */
typedef long long ll;

bool convertibilidad(ll x, ll y, vector<ll>& seq){
    if (seq.empty()) seq.push_back(x);
    if (x > y) return false;  // poda 
    if (x == y) return true;
    seq.push_back(x * 2);
    bool res = convertibilidad(x * 2, y, seq);
    if (res) return res;
    seq.pop_back(); 
    seq.push_back(10*x + 1);
    res = convertibilidad(10*x + 1, y, seq);
    if (res) return res;
    seq.pop_back();
    return false; // :c
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x, y;
    cin >> x >> y; //cin >> | cout <<
    vector<ll> seq;
    if (convertibilidad(x, y, seq)){
        cout << "YES\n" << seq.size() << endl;
        for(auto elem : seq) cout << elem << " ";
        cout << "\n";
    }
    else { 
        cout << "NO\n";
    }
    return 0;
}
