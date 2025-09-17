#include <iostream>
#include <vector>
#include <algorithm>
#include "kp_bounded.cpp"
#include "kp_01.cpp"

int main(){
  int m, n;
  std::cin >> m >> n;
  std::vector<int> wt(n+1), p(n+1);
  std::vector<std::vector<int>> kp(n+1, std::vector<int>(m+1));
  for (int i=1; i<=n; i++) std::cin >> wt[i]; // i=1 sistema tutto
  for (int i=1; i<=n; i++) std::cin >> p[i]; // beneficios
  std::cout << kp_01(n, m, wt, p, kp) << std::endl;
  std::cout << kp_bounded(n, m, wt, p, kp) << std::endl;
  }
}