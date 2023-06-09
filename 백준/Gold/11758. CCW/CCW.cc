#include <iostream>

using namespace std;

struct point{
    int x;
    int y;
};

int ccw(point* ps){
    long long t1 = ps[0].x * ps[1].y + ps[1].x * ps[2].y + ps[2].x * ps[0].y;
    long long t2 = ps[0].y * ps[1].x + ps[1].y * ps[2].x + ps[2].y * ps[0].x;

    if (t1 - t2 > 0) return 1;
    else if(t1 - t2 == 0) return 0;
    else return -1;
}

int main(){
    point p[3];
    int _x, _y;
    for(int i = 0; i < 3; i++){
        cin >> p[i].x >> p[i].y;
    }

    cout << ccw(p);
}