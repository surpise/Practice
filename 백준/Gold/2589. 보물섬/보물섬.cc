#include <iostream>
#include <queue>

using namespace std;

int r, c, ans;
char tm[50][50];
bool v[50][50];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
queue<pair<pair<int, int>, int>> q;

void bfs(){
    int _r = q.front().first.first, _c = q.front().first.second, cnt = q.front().second;
    q.pop();
    if(!v[_r][_c]){
        v[_r][_c] = 1;
        int tr, tc;
        for(int i = 0; i < 4; i++){
            tr = _r + dr[i];
            tc = _c + dc[i];
            if(tr < 0 || tr >= r || tc < 0 || tc >= c) continue;
            
            if(!v[tr][tc] && tm[tr][tc] == 'L') q.push({{tr, tc}, cnt + 1});
        }
        if(cnt > ans)ans = cnt;
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cin >> tm[i][j];
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(tm[i][j] == 'L'){
                for(int a = 0; a < r; a++){
                    for(int b = 0; b < c; b++) v[a][b] = 0;
                }
                q.push({{i, j}, 0});
                while(!q.empty()){
                    bfs();
                }
            }
        }
    }
    cout << ans;
}