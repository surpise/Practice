#include <iostream>
#include <string>
using namespace std;

int main(){
    int max = -1, x, y, n;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++) {
            cin >> n;
            if(max < n){
                max = n;
                x = i;
                y = j;
            }
        }
    }
    cout << max << '\n' << x << " " << y;
}