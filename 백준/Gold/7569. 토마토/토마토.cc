#include <iostream>
#include <queue>
using namespace std;
int m, n, l, ans = 0;
int arr[100][100][100];
int v[100][100][100];
struct box{int height, col, row, day;};
queue<box> que;

void bfs(box b){
    int h = b.height, c = b.col, r = b.row, d = b.day;
    if(!v[h][c][r] && arr[h][c][r] != -1){
        v[h][c][r] = 1;
        arr[h][c][r] = 1;
        ans = d;
        for(int i = -1; i < 2; i += 2){
            if(h + i >= 0 && h + i < l) que.push({h + i, c, r, d + 1});
            if(c + i >= 0 && c + i < n) que.push({h, c + i, r, d + 1});
            if(r + i >= 0 && r + i < m) que.push({h, c, r + i, d + 1});
        }
    }
}

int main(){
    cin >> m >> n >> l;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++) {
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1) que.push({i, j, k, 0});
            }
        }
    }

    while(!que.empty()){
        bfs(que.front());
        que.pop();
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(arr[i][j][k] == 0) ans =-1;
            }
        }
    }
    cout << ans;
}