#include <iostream>

using namespace std;

bool arr[4000001] = {1, 1, };
unsigned long long prime[4000001];

int main(){
    int n;
    cin >> n;

    for(unsigned long long i = 2; i <= n; i++){
        for(unsigned long long j = i; i * j <= n; j++){
            arr[i * j] = 1;
        }
    }
    
    int idx = 1;
    for(int i = 2; i <= n; i++){
        if(!arr[i]) prime[idx++] = i;
    }
    int a = 0, b = 0, ans = 0;
    unsigned long long sum = 0;
    while(a <= b){
        if(sum > n){
            a++;
        }
        else{
            if(sum == n) ans++;
            b++;
        }
        sum = 0;
        for(int i = a; i <= b; i++){
            sum += prime[i];
        }
        if(!prime[b]) break;
    }
    cout << ans;
}