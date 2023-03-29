#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res = 0;
int arr[500][500];
bool v[500][500];
int dd[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, int l, int sum){
    if(l == 4) res = max(res, sum);
    else{
        for(int i = 0; i < 4; i++){
            int dx = dd[i][0] + x;
            int dy = dd[i][1] + y;
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;

            if(!v[dx][dy]){
                v[dx][dy] = 1;
                dfs(dx, dy, l + 1, sum + arr[dx][dy]);
                v[dx][dy] = 0;
            }
        }
    }
    return;
}

void ff(int x, int y){
    int r = 0, c = 0;
    if(x + 2 < n){
        int a = 0, b = 0;
        for(int i = 0; i < 3; i++) r += arr[x + i][y];
        if(y + 1 < m) a = arr[x + 1][y + 1];
        if(y - 1 >= 0) b = arr[x + 1][y - 1];
        (a > b) ? r += a : r += b;
    }
    if(y + 2 < m){
        int a = 0, b = 0;
        for(int i = 0; i < 3; i++) c += arr[x][y + i];
        if(x + 1 < n) a = arr[x + 1][y + 1];
        if(x - 1 >= 0) b = arr[x - 1][y + 1];
        (a > b) ? c += a : c += b;
    }
    res = max({res, r, c});
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            v[i][j] = 1;
            dfs(i, j, 1, arr[i][j]);
            v[i][j] = 0;
            ff(i, j);
        }
    }
    cout << res;
}