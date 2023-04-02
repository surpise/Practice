#include <iostream>
#include <string>
using namespace std;

int main(){
    int a[100][100] = {0, };
    int n, m, tmp;
    cin >> n >> m;
    for(int t = 0; t < 2; t++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> tmp;
                a[i][j] += tmp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << a[i][j] << " ";
        cout << endl;
    }
}