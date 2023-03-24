#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
bool v[101];
queue<pair<int, int>> que;
int n, m, cnt, midx, minum = 5000;
void bfs(int x, int d){
    if(!v[x]){
        v[x] = 1;
        cnt += d;

        for(int i = 1; i <= n; i++){
            if(arr[x][i] == 1) {
                que.push({i, d + 1});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int i = 1; i <= n; i++){
        v[i] = 1;
        cnt = 0;
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == 1) que.push({j, 1});
        }
        while(!que.empty()){
            bfs(que.front().first, que.front().second);
            que.pop();
        }
        if(cnt < minum) {
            minum = cnt;
            midx = i;
        }
        for(int i = 1; i <= n; i++) v[i] = 0;
    }
    cout << midx;
}