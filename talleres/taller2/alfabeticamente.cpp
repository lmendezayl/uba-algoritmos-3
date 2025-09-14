#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> c(n);
    vector<string> s(n), rev(n);

    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    for (int i = 0; i < n; i++){
        cin >> s[i];
        rev[i] = s[i];
        reverse(rev[i].begin(), rev[i].end());
    }
    // dp vector 2x2 de infs
    long long inf = 1e18;

    vector<vector<long long>> dp(2, vector<long long>(2, inf)); 
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (int i=1; i<n; i++){
      // no invierto dp[1][0]
      if (s[i] >= s[i-1]) dp[1][0] = min(dp[1][0], dp[0][0]);
      if (s[i] >= rev[i-1]) dp[1][0] = min(dp[1][0], dp[0][1]);
      // invierto (dp[1][1])
      if (rev[i] >= s[i-1]) dp[1][1] = min(dp[1][1], dp[0][0] + c[i]);
      if (rev[i] >= rev[i-1]) dp[1][1] = min(dp[1][1], dp[0][1] + c[i]);
      
      dp[0][0] = dp[1][0];
      dp[0][1] = dp[1][1];
      
      if (dp[0][0] == inf && dp[0][1] == inf){
        cout << -1 << endl;
        return 0;
      }  
      
      dp[1][0] = dp[1][1] = inf;
    }
    
    cout << min(dp[0][0], dp[0][1]);
    return 0;
}
