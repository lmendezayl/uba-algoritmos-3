#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<ll> c, vector<string>){
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin >> n;
    int i = 0;
    vector<ll> c(n);
    vector<string> s(n);
    while(i < n){
        cin >> c[i];
        i++;
    }
    i = 0;
    while(i < n){
        cin >> s[i];
        i++;
    }

    int ans = solve(c, s);
    return 0;
}
