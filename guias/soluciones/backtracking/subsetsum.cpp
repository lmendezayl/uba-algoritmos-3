#include <iostream>
#include <vector>
using namespace std;

// voy a implementar la funcion de subset_sum del ejercicio 1 pero no la que
// implementa la funcion con vector, sino solamente la que verifica si existe
// o no una solucion válida

bool subsetsum(vector<int> C, int i, int j){
    if (j < 0) return false; // me pase de j, aplico poda
    if (j == 0) return true; // elijo hijo izquierdo => no sumo a j => existe sol
    return subsetsum(C, i - 1, j) || subsetsum(C, i - 1,  j - C[i]);
}

int main(){
    int n, k;
    cin >> n;
    vector<int> C(n);
    int i = 0;
    while(i < n){
        cin >> C[i];
        i++;
    }
    cout << subsetsum(C, n-1, k) << endl;
    return 0;
}
