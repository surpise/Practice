#include <iostream>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int>> q[100001];
int v[100001]; 
int n, m, r, cnt = 1;

void dfs(int x){
    v[x] = cnt;
    cnt++;
    while(!q[x].empty()){
        if(!v[q[x].top()]) dfs(q[x].top());
        q[x].pop();
    }
}

int main(){
    cin >> n >> m >> r;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        q[a].push(b);
        q[b].push(a);
    }
    dfs(r);
    for(int i = 1; i <= n; i++) cout << v[i] << '\n';
}