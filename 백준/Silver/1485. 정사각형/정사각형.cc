#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct point{
    int x, y;
};

bool cmp(point a, point b){
    if(a.x < b.x) return true;
    else if(a.x == b.x){
        if(a.y < b.y) return true;
    }
    return false;
}

long long calcD(point a, point b){
    long long t1 = (a.x - b.x) * (a.x - b.x);
    long long t2 = (a.y - b.y) * (a.y - b.y);
    return t1 + t2;
}

int main(){
    int tc, cnt;
    cin >> tc;

    point p[4];
    long long d[4][4];
    for(int t = 0; t < tc; t++){
        for(int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
        sort(&p[0], &p[4], cmp);
        long long d1 = calcD(p[0], p[1]);
        long long d2 = calcD(p[0], p[2]);
        long long d3 = calcD(p[1], p[3]);
        long long d4 = calcD(p[2], p[3]);
        long long d5 = calcD(p[0], p[3]);
        long long d6 = calcD(p[1], p[2]);
        
        bool ans = (d1 == d2) && (d1 == d3) && (d1 == d4) && (d5 == d6);
        if(ans) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}