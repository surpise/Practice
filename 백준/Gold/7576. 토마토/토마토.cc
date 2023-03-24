#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n, cnt;
int arr[1000][1000];
bool visited[1000][1000];

queue<pair<pair<int, int>, int>> que;
void bfs(int r, int c, int d){
    if(!visited[r][c] && arr[r][c] != -1){
        arr[r][c] = (d == 0) ? 1 : d;
        cnt = d;
        visited[r][c] = true;
        for(int i = -1; i < 2; i += 2){
            if(r + i >= 0 && r + i < n && arr[r + i][c] != -1){
                if(!visited[r + i][c]) que.push({{r + i, c}, d + 1});
            } 
            if(c + i >= 0 && c + i < m && arr[r][c + i] != -1){
                if(!visited[r][c + i]) que.push({{r, c + i}, d + 1});
            }
        }
    }
}

int main(){
    cin >> m >> n;

    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) que.push({{i, j}, 0});
        }
    }

    while(!que.empty()){
        bfs(que.front().first.first, que.front().first.second, que.front().second);
        que.pop();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0) {
                cnt = -1;
                break;
            }
        }
    }
    cout << cnt;
}