#include <iostream>
#include <queue>

using namespace std;

int n, k, s, x, y;
int arr[201][201];
bool v[201][201];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

struct virus{
    int row, col;
    int vNum;
    virus(int x, int y, int n) : row(x), col (y), vNum(n){}
    bool operator<(const virus v) const{
        return this->vNum > v.vNum;
    }
};
priority_queue<virus> q;


void bfs(){
    int r, c, vir, tr, tc;
    for(int i = 0; i < s; i++){
        priority_queue<virus> tq;
        while(!q.empty()){
            r = q.top().row, c = q.top().col, vir = q.top().vNum;
            q.pop();
            v[r][c] = 1;
            for(int i = 0; i < 4; i++){
                tr = r + d[0][i], tc = c + d[1][i];
                if(tr < 1 || tr > n || tc < 1 || tc > n) continue;
                if(!v[tr][tc] && arr[tr][tc] == 0){
                    tq.push(virus(tr, tc, vir));
                    arr[tr][tc] = arr[r][c];
                }
            }
        }
        q = tq;
    }
    cout << arr[x][y];
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] != 0) q.push(virus(i, j, arr[i][j]));
        }
    }

    cin >> s >> x >> y;

    bfs();
}