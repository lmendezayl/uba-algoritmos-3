#include <iostream>
#include <vector> 
 
int tsp(const std::vector<std::vector<int>>& D, std::vector<bool>& visitado,
        int nodo_actual, int costo_acum, int& mejor_solucion, int n, int nivel){
    
    // poda por factibilidad: no puedo mejorar solucion siguiendo por esta rama
    if (costo_acum >= mejor_solucion) return mejor_solucion;
    if (nivel == n) { // llegue al ultimo nivel
        // sumo la vuelta del nodo n al nodo 1
        costo_acum += + D[nodo_actual][0]; 
        // si esta rama tiene solucion mejor, actualizo
        if (costo_acum < mejor_solucion) mejor_solucion = costo_acum;
        return mejor_solucion;
    }
    
    // recorro todas las ramas
    for (int i=0; i<n; i++){
        if (!visitado[i]){ // si no visite el nodo actual
            visitado[i] = true;
            // no asigno variable a tsp(...) porque actualiza mejor_solucion
            tsp(D, visitado, i, costo_acum + D[nodo_actual][i], mejor_solucion, n, nivel + 1);
            visitado[i] = false;
        }
    }
    
    // termine de recorrer todas las ramas factibles
    return mejor_solucion;
}

int main(){
    int n; std::cin >> n;
    std::vector<std::vector<int>> D(n, std::vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) std::cin >> D[i][j]; // armo matriz de pesos
    }
    
    std::vector<bool> visitado(n, false); // vector de chequeo de visita de nodos
    visitado[0] = true; // inicializamos el tsp con el primer nodo
    int inf = 1e7; // para comparar con primer solucion candidata
    
    // tsp(D, visitado, nodo_actual, costo_acum, mejor_solucion, n, nivel)
    int res = tsp(D, visitado, 0, 0, inf, n, 1);
    std::cout << res << std::endl;
    return 0;
}