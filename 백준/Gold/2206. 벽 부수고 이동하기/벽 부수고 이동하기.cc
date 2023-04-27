#include <iostream>
#include <queue>
#include <array>

using namespace std;

queue<array<int, 4>> q;
int arr[1001][1001];
bool v[1001][1001];
bool bv[1001][1001];
int dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0};
int n, m, f;

void bfs(){
    int y = q.front()[0], x = q.front()[1];
    int bomb = q.front()[2], cnt = q.front()[3];
    q.pop();
    if(y == n && x == m){
        f = 1;
        cout << cnt;
        while(!q.empty()) q.pop();
        return;
    }
    if(!v[y][x] || (bomb && !bv[y][x])){
        v[y][x] = 1;
        if(bomb) bv[y][x] = 1;
        for(int i = 0; i < 4; i++){
            if(y + dy[i] >= 1 && y + dy[i] <= n){
                if(x + dx[i] >= 1 && x + dx[i] <= m){
                    if(bomb && arr[y + dy[i]][x + dx[i]]){
                        q.push({y + dy[i], x + dx[i], 0, cnt + 1});
                    }
                    else if(!arr[y + dy[i]][x + dx[i]]){
                        q.push({y + dy[i], x + dx[i], bomb, cnt + 1});
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    string str;
    for(int i = 1; i <= n; i++){
        cin >> str;
        for(int s = 0; s < m; s++) arr[i][s + 1] = (str[s] == '1') ? 1 : 0;
    }
    
    q.push({1, 1, 1, 1});
    while(!q.empty()){
        bfs();
    }
    if(!f) cout << -1;
}