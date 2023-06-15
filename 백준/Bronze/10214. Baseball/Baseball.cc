#include <iostream>

using namespace std;

int main(){
    int t, y, k, _y, _k;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        y = 0;
        k = 0;
        for(int i = 0; i < 9; i++){
            cin >> _y >> _k;
            y += _y;
            k += _k;
        }
        if(y > k) cout << "Yonsei\n";
        else if(y < k) cout << "Korea\n";
        else cout << "Draw\n";
    }
}