#include <stdc++.h>
using namespace std;

void kp(int N, int M){
    for (j = 1; j <= N; j++){
        for (i = 1; i <= M; i++)
            if (i >= size[j])
                if (cost[i] < cost[i - size[j]] + val[j]){
                    cost[i] = cost[i - size[j]] + val[j];
                    best[i] = j;
                }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    kp(N, M);
    return 0
}
