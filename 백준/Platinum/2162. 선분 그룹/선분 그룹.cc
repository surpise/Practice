#include <iostream>
#include <vector>

using namespace std;

struct point{
    long long x, y;
};

struct line{
    point a, b;
};
line larr[3001];
int p[3001];
int res[3001];

int ccw(point a, point b, point c){
    long long t1 = a.x * b.y + b.x * c.y + c.x * a.y;
    long long t2 = a.y * b.x + b.y * c.x + c.y * a.x;
    if(t1 - t2 > 0) return 1;
    else if(t1 - t2 == 0) return 0;
    else return -1;
}

int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}

void un(int u, int v){
    p[find(u)] = find(v);
}

bool isCross(line l1, line l2){
    bool ans = false;
    long long mx1 = min(l1.a.x, l1.b.x), my1 = min(l1.a.y, l1.b.y);
    long long mx2 = max(l1.a.x, l1.b.x), my2 = max(l1.a.y, l1.b.y);
    long long mx3 = min(l2.a.x, l2.b.x), my3 = min(l2.a.y, l2.b.y);
    long long mx4 = max(l2.a.x, l2.b.x), my4 = max(l2.a.y, l2.b.y);

    if((ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b) <= 0) && (ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b) <= 0)){
        if(mx1 > mx4 || mx3 > mx2) ans = false;
        else if(my1 > my4 || my3 > my2) ans = false;
        else ans = true;
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> larr[i].a.x >> larr[i].a.y >> larr[i].b.x >> larr[i].b.y;
        p[i] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(isCross(larr[i], larr[j])){
                un(i, j);
            }
        }
    }

    int sz = 0, big = 0;
    for(int i = 1; i <= n; i++) res[find(i)]++;
    for(int i = 1; i <= n; i++){
        if(res[i] > 0) sz++;
        if(res[i] > big) big = res[i];
    }
    cout << sz << '\n' << big;
}