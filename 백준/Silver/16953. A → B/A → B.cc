#include <iostream>
#include <queue>

using namespace std;

long a, b, ans;
queue<pair<long, int>> q;

void res(int r){
    ans = r;
    while(!q.empty()) q.pop();
}

void bfs(){
    long x = q.front().first;
    int ans = q.front().second;
    q.pop();
    long n = x * 2;
    long m = x * 10 + 1;
    if(n == b || m == b) res(ans + 1);
    else {
        if(n < b) q.push({n, ans + 1});
        if(m < b) q.push({m, ans + 1});
    }
}

int main(){
    cin >> a >> b;
    q.push({a, 1});
    while(!q.empty()) bfs();
    
    if (ans == 0) cout << -1;
    else cout << ans;
}