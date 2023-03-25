#include <iostream>
using namespace std;

char arr[6561][6561];

void star(int x, int y, int d){
    if(d == 3) arr[x - 1][y - 1] = ' ';
    else{
        for(int i = 2 * (d / 3); i >= 0; i -= d / 3 ){
            for(int j = 2 * (d /3); j >= 0; j -= d / 3){
                if(i == d / 3 && j == d / 3){
                    for(int n = 0; n < d / 3; n++){
                        for(int m = 0; m < d / 3; m++){
                            arr[x - i -n][y - j - m] = ' ';
                        }
                    }
                }
                else {
                    star(x - i, y - j, d / 3);
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) arr[i][j] = '*';
    }
    star(n - 1, n - 1, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << arr[i][j];
        cout << endl;
    }
}