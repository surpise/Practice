#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q[100001];
queue<int> bfsq;
int v[100001];
int cnt = 1;

void bfs(){
    int x = bfsq.front();
    bfsq.pop();
    if(!v[x]){
        v[x] = cnt;
        cnt++;
        while(!q[x].empty()){
            if(!v[q[x].top()]) bfsq.push(q[x].top());
            q[x].pop();
        }
    }
}

int main(){
    int n, m, r, a, b;
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        q[a].push(b);
        q[b].push(a);
    }
    bfsq.push(r);
    while(!bfsq.empty()) bfs();
    for(int i = 1; i <= n; i++) cout << v[i] << '\n';
}