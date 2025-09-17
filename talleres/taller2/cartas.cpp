#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main(){
    int n, k, res; // n jugadores, k cartas por jugador
    std::cin >> n >> k;
    std::vector<int> c(n*k), f(n), h(k+1); // c valores de nk cartas, f cartas favoritas de jugadores, h alegria por cantidad de cartas
    for (int i=0; i<n*k; i++) std::cin >> c[i];
    for (int i=0; i<n; i++) std::cin >> f[i];
    for (int i=1; i<=k; i++) std::cin >> h[i];
        
    // juntamos las cartas en base a cantidad de cartas por valor
    std::map<int, int> cant_cartas; 
    for (int carta : c) cant_cartas[carta] += 1; // ok

    // agrupo a los jugadores por carta favorita
    std::map<int, std::vector<int>> grupos_fav;
    for (int i=0; i<n; i++) grupos_fav[f[i]].push_back(i);
    
    res = 0;
    
    // para cada grupo de jugadores
    for (const auto& [fav, jugadores] : grupos_fav){
        // hacemos kp
        int col = cant_cartas[fav]; // cantidad de cartas de numero fav
        int fil = jugadores.size(); // cantidad de jugadores con carta favorita fav
        
        // definimos matriz dp[fil][col]
        std::vector<std::vector<int>> kp(fil+1, std::vector<int>(col+1)); 
        
        // para cada jugador del grupo
        for (int i=0; i<=fil; i++){
            // para cada carta
            for (int j=0; j<=col; j++){
                // caso base: no darle nada al jugador i
                kp[i][j] = kp[i-1][j]; // crea vector de ceros
                // ahora probamos darle x cartas (si entra en la capacidad)
                for (int x=1; x<=k && x<=j; x++) {
                  kp[i][j] = std::max(kp[i][j], kp[i-1][j-x] + h[x]);
                }
            }
        }
        // sumamos kp del grupo 
        res += kp[fil][col];
        
        for (int i=0; i<=fil; i++){
            for (int j=0; j<=col; j++){
              std::cout << kp[i][j] << " ";
            }
        std::cout << std::endl;
        }
    }    
    std::cout << res << std::endl;
    return 0;
}
