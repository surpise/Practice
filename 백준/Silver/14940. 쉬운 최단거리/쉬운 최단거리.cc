#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1000][1000];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
bool v[1000][1000];
queue<pair<int, int>> q;

void bfs(){
    int r, c, _r, _c;
    while(!q.empty()){
        r = q.front().first, c = q.front().second;
        v[r][c] = 1;
        q.pop();
        for(int i = 0; i < 4; i++){
            _r = r + d[0][i];
            _c = c + d[1][i];
            if(_r < 0 || _r >= n || _c < 0 || _c >= m) continue;
            if(arr[_r][_c] == 1 && !v[_r][_c]){
                arr[_r][_c] = arr[r][c] + 1;
                q.push({_r, _c});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) {
                q.push({i, j});
                arr[i][j] = 0;
            }
        }
    }

    bfs();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(arr[i][j] != 0 && !v[i][j]) cout << -1 << " ";
            else cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}