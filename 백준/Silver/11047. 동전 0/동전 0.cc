#include <stdio.h>

using namespace std;

int main(){
    int N, K, ans = 0;
    int coin[10];

    scanf(" %d %d", &N, &K);
    for (int i = N - 1; i >= 0; i--){
        scanf(" %d", &coin[i]);
    }

    for (int i = 0; i < N; i++){
        if(coin[i] <= K){
            ans += K / coin[i];
            K = K % coin[i];
        }   
    }

    printf("%d", ans);
}