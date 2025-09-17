#include <iostream>
#include <vector>
#include <algorithm>

void kp_01(int n, int m, vector<int> wt, vector<int> p, vector<vector<int>> kp){
  // logica del kp
  for (int i=0; i<=n; i++){
    for (int w=0; w<=m; w++){
      if (i == 0 || w == 0){
        // no tengo objetos o no tengo capacidad
        kp[i][w] = 0;
      }
      else if (wt[i] <= w){
        // evaluamos si es mejor agregar el objeto o tomar el anterior
        kp[i][w] = std::max(p[i] + kp[i-1][w-wt[i]], kp[i-1][w]); 
      }
      else {
        // caso que me pasé de capacidad y tengo objetos todavia
        kp[i][w] = kp[i-1][w];
      }
    }
  }
  for (int i=0; i<=n; i++){
    for (int j=0; j<=m; j++){
      std::cout << kp[i][j] << " ";
    }
    std::cout << std::endl;
  }

}