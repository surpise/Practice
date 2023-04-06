#include <iostream>
using namespace std;

int main(){
    int n, cnt;
    cin >> n;
    
    while(n > 1){
        for(int i = 2; i <= n; i++){
            if(n % i == 0){
                cnt = 0;
                for(int j = 2; j < i; j++){
                    if(i % j == 0) {
                        cnt = 1;
                        break;
                    }
                }
                if(cnt == 0){
                    cout << i << endl;
                    n /= i;
                    break;
                }
            }
        }
    }
}