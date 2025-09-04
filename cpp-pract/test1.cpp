#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> ceros(3,0);
vector<int> enteros = {1,2,3};

void apunte_facu(){
    ios::sync_with_stdio(false); // hacen el io un toque mas rapido
    cin.tie(NULL);
    int x;
    int y;
    cin >> x >> y;
    cout << x+y << "\n";

    for (int k: enteros)
    {
        cout << k << "\n";
    }
    enteros.resize(5);
    enteros.push_back(3);
    enteros[2] = 5;
    cout << enteros.back() << "\n" << enteros.front() << "\n";
    cout << enteros.size() << "\n";

    // Arreglos
    // Constructores
    int fibo[3]; // asigno 3 espacios, tienen tamaño fijo, cuesta O(1)
    memset(fibo, 1, sizeof(fibo));

    fibo[2] = 3; // acceso
    
    vector<int> v = {5, 3, 2, 1, 4};
    sort(v.begin(), v.end());
    for (int vi: v){
        cout << vi << endl;
    }
}

int main(){

}


