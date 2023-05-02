#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    a %= b;
    for(int i = 0; i < c - 1; i++){
        a *= 10;
        a %= b;
    }
    cout << (a * 10) / b;
}