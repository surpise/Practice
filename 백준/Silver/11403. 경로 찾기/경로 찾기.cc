#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[101][101];
bool v[101][101];
queue<pair<pair<int, int>, int>> que;

void bfs(int x, int y, int s){
    if(y != s){
        arr[s][y] = 1;
        v[s][y] = 1;
        if(y == s) arr[y][s] == 1;
        for(int i = 0; i < n; i++){
            if(arr[y][i] == 1 && !v[s][i]) que.push({{y, i}, s});
        }
    }
    else arr[s][s] = 1;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                que.push({{i, j}, i});
            }
        }
    }
    while(!que.empty()){
        bfs(que.front().first.first, que.front().first.second, que.front().second);
        que.pop();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << arr[i][j] << " ";
        cout << '\n';
    }
}