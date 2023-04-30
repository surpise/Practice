#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int xs, ys, xe, ye, dx, dy;
    cin >> xs >> ys;
    cin >> xe >> ye >> dx >> dy;

    if(dx == 0) dy = 1;
    else if(dy == 0) dx = 1;
    else{
        int a = min(dx, dy);
        while(a){
            if(dx % a == 0 && dy % a == 0) break;
            a--;
        }
        if(a > 1){
            dx /= a;
            dy /= a;
        }
    }
    int rx = xe, ry = ye;
    if(dx != 0 || dy != 0){
        double d = sqrt(pow(abs(xs - xe), 2) + pow(abs(ys - ye), 2)), id = d, td;
        while(d <= id){
            xe += dx;
            ye += dy;
            td = sqrt(pow(abs(xs - xe), 2) + pow(abs(ys - ye), 2));
            if(td < d) {
                rx = xe;
                ry = ye;
            }
            else if(td == d){
                if(abs(xs - xe) + abs(ys - ye) < abs(xs - xe - dx) + abs(ys - ye - dy)){
                    rx = xe;
                    ry = ye;
                }
            }
            d = td;
        }
    }  
    cout << rx << " " << ry;
}