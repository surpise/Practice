#include <iostream>
#include <algorithm>

using namespace std;

struct point{
    long long x, y;
};
struct line{
    point a, b;
};

int ccw(point a, point b, point c){
    long long t1 = a.x * b.y + b.x * c.y + c.x * a.y;
    long long t2 = a.y * b.x + b.y * c.x + c.y * a.x;

    if(t1 - t2 > 0) return 1;
    else if(t1 - t2 == 0) return 0;
    else return -1;
}

bool isCross(line l1, line l2){
    bool res = false;
    long long mx1 = min(l1.a.x, l1.b.x), my1 = min(l1.a.y, l1.b.y);
    long long mx2 = max(l1.a.x, l1.b.x), my2 = max(l1.a.y, l1.b.y);
    long long mx3 = min(l2.a.x, l2.b.x), my3 = min(l2.a.y, l2.b.y);
    long long mx4 = max(l2.a.x, l2.b.x), my4 = max(l2.a.y, l2.b.y);
    if((ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b) <= 0) && (ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b) <= 0)){
        if(mx1 > mx4 || mx3 > mx2) res = false;
        else if(my1 > my4 || my3 > my2) res = false;
        else res = true;
    }
    return res;
}

bool isIn(line l, long long _x1, long long _y1, long long _x2, long long _y2){
    bool res = false;
    long long sx = min(_x1, _x2), lx = max(_x1, _x2);
    long long sy = min(_y1, _y2), ly = max(_y1, _y2);

    if(l.a.x > sx && l.b.x > sx && l.a.x < lx && l.b.x < lx){
        if(l.a.y > sy && l.b.y > sy && l.a.y < ly && l.b.y < ly) res = true;
    }
    return res;
}

int main(){
    int t;
    char ans;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        ans = 'F';
        line l;
        cin >> l.a.x >> l.a.y >> l.b.x >> l.b.y;

        long long x1, y1, x2, y2;
        line sq[4];
        cin >> x1 >> y1 >> x2 >> y2;
        sq[0].a.x = x1, sq[0].a.y = y1, sq[0].b.x = x1, sq[0].b.y = y2;
        sq[1].a.x = x2, sq[1].a.y = y1, sq[1].b.x = x2, sq[1].b.y = y2;
        sq[2].a.x = x1, sq[2].a.y = y1, sq[2].b.x = x2, sq[2].b.y = y1;
        sq[3].a.x = x1, sq[3].a.y = y2, sq[3].b.x = x2, sq[3].b.y = y2;

        for(int i = 0; i < 4; i++){
            if(isCross(l, sq[i])) ans = 'T';
        }
        if(isIn(l, x1, y1, x2, y2)) ans = 'T';
        cout << ans << '\n';
    }
}