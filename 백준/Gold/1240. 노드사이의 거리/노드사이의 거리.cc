#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001];
bool v[1001];
int n, m, dist;
queue<pair<int, int>> q;

void bfs(){
    int r, d;
    while(!q.empty()){
        r = q.front().first;
        d = q.front().second;
        v[r] = 1;
        q.pop();
        if(r == dist){
            cout << d << '\n';
            break;
        }
        for(int i = 1; i <= n; i++){
            if(i == r) continue;
            if(!v[i] && arr[r][i] != 0){
                q.push({i, arr[r][i] + d});
            }
        }
    }
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; i++) v[i] = 0;
}

int main(){
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b >> c;
        arr[a][b] = c;
        arr[b][a] = c;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        q.push({a, 0});
        dist = b;
        bfs();
    }
}