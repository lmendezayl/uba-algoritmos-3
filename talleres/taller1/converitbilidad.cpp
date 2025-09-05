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

bool convertibilidad(int x, int y, vector<int>& seq){
    if (seq.empty()) seq.push_back(x);
    if (x > y) return false;  // poda 
    if (x == y) return true;
    
    seq.push_back(x * 2);
    res = convertibilidad(x * 2, y, seq);
    if (!res.empty()) return true;

    seq_aux = seq; // clanker de seq pq sino no me deja insertar 
    seq_aux.insert(10*x + 1);
    res = convertibilidad(10*x + 1, y, seq_aux);
    if (!res.empty()) return res;
    
    return {}; // :c
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x >> y; //cin >> | cout <<
    vector<int> seq;
    if (convertibilidad(x, y, ){
        cout << "YES\n" << res.size() << endl;
        for(auto elem : res) cout << elem << " ";
    }
    else { 
        cout << "NO\n";
    }
    return 0;
}
