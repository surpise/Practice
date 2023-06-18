#include <iostream>

using namespace std;

int main(){
    int a, ax, ay, b, bx, by;
    cin >> a >> b;
    ax = a / 4;
    ay = a % 4;
    if(ay != 0) ax++;
    else ay = 4;

    bx = b / 4;
    by = b % 4;
    if(by != 0) bx++;
    else by = 4;

    cout << abs(ax - bx) + abs(ay - by);
}