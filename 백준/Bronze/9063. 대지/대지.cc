#include <iostream>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;

    int xs = 10000, xb = -10000, ys = 10000, yb = -10000;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a < xs) xs = a;
        if(a > xb) xb = a;
        if(b < ys) ys = b;
        if(b > yb) yb = b;
    }

    cout << (xb - xs) * (yb - ys);
}