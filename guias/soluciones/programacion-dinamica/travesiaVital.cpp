#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vint;

int solve(vector<vint>& A){
    for  
}


int f(int i, int j){
    if(i == 0 && j == 0) return A[0][0];
    if(i < 0 || j < 0) return INT_MIN;
    return A[i][j] + max(f(i-1, j), f(i, j-1));
}

int main(){
    int n, m; cin >> n >> m;
    vector<vint> A(n, vint(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) cin >> A[i][j];
    }

    int res; res = solve(A);
    return 0;
}
