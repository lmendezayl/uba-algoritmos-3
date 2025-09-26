#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vint;

vint A(3, vint(3));

int f(int i, int j){
    if(i == 0 && j == 0) return A[0][0];
    if(i < 0 || j < 0) return INT_MIN;
    return A[i][j] + max(f(i-1, j), f(i, j-1));
}

int main(){

}