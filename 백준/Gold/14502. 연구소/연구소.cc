#include <iostream>
#include <queue>

using namespace std;

int n, m, wall, ans;
int arr[8][8], d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
bool v[8][8];
queue<pair<int, int>> q;

int findSafe(){
    int virus = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 1) virus++;
        }
    }
    return n * m - (virus + wall + 3);
}

void bfs(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) v[i][j] = 0;
    }
    queue<pair<int, int>> tq = q;
    int r, c, _r, _c;
    while(!tq.empty()){
        r = tq.front().first, c = tq.front().second;
        v[r][c] = 1;
        tq.pop();
        for(int i = 0; i < 4; i++){
            _r = r + d[0][i];
            _c = c + d[1][i];
            if(_r < 0 || _r >= n || _c < 0 || _c >= m) continue;
            if(!arr[_r][_c] && !v[_r][_c]) tq.push({_r, _c});
        }
    }
    
    int d = findSafe();
    if(ans < d) ans = d;
}


void find(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0) {
                arr[i][j] = 1;
                find(cnt + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) q.push({i, j});
            if(arr[i][j] == 1) wall++;
        }
    }
    
    find(0);
    cout << ans;
}