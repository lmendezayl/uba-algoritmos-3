#include <bits/stdc++.h> // include standard c++ headers, ahorra lineas
using namespace std;

int l_lindo(const string& s, int left, int right, char letra){
    int n = right - left;
    if (n == 1) return (s[left] == letra) ? 0 : 1;
    int medio = n / 2;
    int suma_izq = 0;
    int suma_der = 0;
    for (int i = left; i < left + medio; i++) if (s[i] == letra) suma_izq++;
    for (int i = left + medio; i < right; i++) if (s[i] == letra) suma_der++;    
    int izq = medio - suma_izq + l_lindo(s, left + n/2, right, letra + 1);
    int der = medio - suma_der + l_lindo(s, left, left + n/2, letra + 1);
    return min(izq, der);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if(!(cin >> t)) return 0; // magia de lakso
    while (t--){ // mientras que t > 0, aplica t-- en cada ciclo
        int n;
        string s;
        cin >> n >> s;
        // tenes que construir string_view de s, no podemos pasarlo así nomas
        int res = l_lindo(s, 0, n, 'a'); // en ascii 'a' + 1 = b
        cout << res << endl;
    }
    return 0;
}

