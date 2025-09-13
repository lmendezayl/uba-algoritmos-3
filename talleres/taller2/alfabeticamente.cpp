#include <iostream>
#include <string>
#include <vector> 
using namespace std;


int solve(vector<int> c, vector<string> s){
    int res = -1;
    for (int i = 0; i < s.lenght(); i++){ 
        int comparar(s[i], s[i+1]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    cin >> n;

    vector<int> c(n);
    vector<string> s(n);
    
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    solve(c, s);
    
    return 0;
}
