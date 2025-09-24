#include <iostream>
#include <vector>
#include <optional>
using namespace std;

// std::optional<bool> permite usar logica trivaluada
vector<vector<optional<bool>>> M(100, vector<optional<bool>>(100));

bool subsetsum(vector<int> C, int i, int j)
{
    if (j < 0) return false; // me pase de j, aplico poda
    if (i = 0) return (j == 0); // elijo hijo izquierdo => no sumo a j => existe sol
    if (!M[i][j].has_value()) M[i][j] = subsetsum(C, i - 1, j) || subsetsum(C, i - 1, j - C[i]);
    return M[i][j].value();
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> C(n); 
    for (int i = 0; i < n; i++) cin >> C[i];
    cout << subsetsum(C, n - 1, k) << endl;
    return 0;
}
