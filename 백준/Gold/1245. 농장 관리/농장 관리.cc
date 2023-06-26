#include <iostream>
#include <queue>

using namespace std;

int n, m, ans;
bool peak;
int arr[100][70];
int dr[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, 1, -1};
bool v[100][70];
queue<pair<int, int>> q;

void bfs(){
    int r, c, tr, tc, cnt;
    while(!q.empty()){
        r = q.front().first, c = q.front().second;
        q.pop();
        if(v[r][c]) continue;
        v[r][c] = 1;

        cnt = 8;
        for(int i = 0; i < 8; i++){
            tr = r + dr[i], tc = c + dc[i];
            if(tr < 0 || tr >= n || tc < 0 || tc >= m) continue;
            if(arr[tr][tc] == arr[r][c]){
                if(!v[tr][tc] && arr[tr][tc] != 0) {
                    q.push({tr, tc});
                }
            } 
            else if(arr[tr][tc] > arr[r][c]) peak = false;
        } 
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!v[i][j] && arr[i][j] != 0){
                peak = true;
                q.push({i, j});
                bfs();
                if(peak) ans++;
            }
        }
    }

    cout << ans;
}