#include <iostream>
#include <tuple>
using namespace std;

tuple<int, int> cazador(bool matrix[][], int n){
    // cin elementos de matriz
    for (int i = 0; i < n; i++){
        cout << "fila " << i << endl;
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        } 
    }


}

int main(){
    int n;
    cin >> n;

    bool matrix[n][n];
    tuple<int, int> res;

    res = cazador(matrix, n);

    if (get<0>(res) != -1)
        cout << "hay un falso en posicion (" << get<0>(res) << " ," << get<1>(res) << ")" << endl;
    else cout << "no hay falsos en la matriz" << endl;
    
    return 0;
}
