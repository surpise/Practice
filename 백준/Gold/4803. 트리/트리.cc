#include <iostream>

using namespace std;

int n, m, x, y, nCnt, lCnt, T;
int arr[501][501];
bool v[501];

void dfs(int _x){
    v[_x] = 1;
    for(int i = 1; i <= n; i++){
        if(i == _x) continue;
        if(arr[_x][i] == 1) {
            if(arr[i][_x] == 1) lCnt++;
            if(!v[i]){
                nCnt++;
                dfs(i);
            }
        }
    }
}

int main(){
    int tc = 1;
    while(1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) arr[i][j] = 0;
            v[i] = 0;
        }

        cin >> n >> m;
        T = 0;
        if (n == 0 && m == 0) break;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            arr[x][y] = 1;
            arr[y][x] = 1;
        }

        for(int i = 1; i <= n; i++){
            nCnt = 1;
            lCnt = 0;
            if(!v[i]) {
                dfs(i);
                if(nCnt - (lCnt / 2) == 1) T++;
            }
        }
        cout << "Case " << tc;
        if(T == 0) cout << ": No trees.\n";
        else if(T == 1) cout << ": There is one tree.\n";
        else cout << ": A forest of " << T << " trees.\n";
        tc++;
    }
}