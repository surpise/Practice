#include <iostream>
#include <queue>

using namespace std;

int n, m, ans;
char arr[600][600];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
bool v[600][600];
queue <pair<int, int>> q;

void bfs(){
    int r, c, _r, _c;
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        if(arr[r][c] == 'P') ans++;
        q.pop();

        for(int i = 0; i < 4; i++){
            _r = r + d[0][i];
            _c = c + d[1][i];
            if(_r < 0 || _r >= n || _c < 0 || _c >= m) continue;
            if(!v[_r][_c] && arr[_r][_c] != 'X') {
                v[_r][_c] = 1;
                q.push({_r, _c});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++) {
            arr[i][j] = str[j];
            if(arr[i][j] == 'I') {
                q.push({i, j});
                v[i][j] = 1;
            }
        }
    }

    bfs();
    if(ans == 0) cout << "TT";
    else cout << ans;
}