#include <iostream>
#include <algorithm>
using namespace std;

struct point{
    long long x;
    long long y;
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
    long long mx1 = min(p[0].x, p[1].x), my1 = min(p[0].y, p[1].y), mx2 = max(p[0].x, p[1].x), my2 = max(p[0].y, p[1].y);
    long long mx3 = min(p[2].x, p[3].x), my3 = min(p[2].y, p[3].y), mx4 = max(p[2].x, p[3].x), my4 = max(p[2].y, p[3].y);

    if(ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]) == 0 && ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]) == 0){
        if(mx1 <= mx4 && mx3 <= mx2 && my1 <= my4 && my3 <= my2) ans = 1;
    }
    else if(ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]) <= 0 && ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]) <= 0) ans = 1;

    cout << ans;
}