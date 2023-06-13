#include <iostream>

using namespace std;

struct point{
    long long x, y;
};

int ccw(point a, point b, point c){
    long long t1 = a.x * b.y + b.x * c.y + c.x * a.y;
    long long t2 = a.y * b.x + b.y * c.x + c.y * a.x;
    if(t1 - t2 > 0) return 1;
    else if(t1 - t2 == 0) return 0;
    else return -1;
}

int main(){
    int ans = 0;
    point p[4];
    for(int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
    if(ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]) < 0){
        if(ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]) < 0) ans = 1;
    }
    cout << ans;
}