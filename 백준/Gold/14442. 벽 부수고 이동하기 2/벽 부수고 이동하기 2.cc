#include <iostream>
#include <queue>
#include <array>
using namespace std;

struct state{
    int sr;
    int sc;
    int sb;
    int sd;
};

int n, m, k;
int arr[1000][1000], dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
bool v[1000][1000][11];
queue<state> q;



void bfs(){
    q.push({0, 0, 0, 1});
    int r, c, b, d, tr, tc;
    while(!q.empty()){
        r = q.front().sr, c = q.front().sc, b = q.front().sb, d = q.front().sd;

        v[r][c][b] = 1;
        q.pop();
        if(r == n - 1 && c == m - 1){
            cout << d;
            return;
        }

        for(int i = 0; i < 4; i++){
            tr = r + dr[i], tc =c + dc[i];
            if(tr < 0 || tr >= n || tc < 0 || tc >= m || v[tr][tc][b]) continue;
            if(arr[tr][tc]){
                if(b < k && !v[tr][tc][b + 1]){
                    q.push({tr, tc, b + 1, d + 1});
                    v[tr][tc][b + 1] = 1;
                }
            }
            else{
                q.push({tr, tc, b, d + 1});
                v[tr][tc][b] = 1;
            }
        }
    }
    cout << -1;
}

int main(){
    cin >> n >> m >> k;

    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++) arr[i][j] = str[j] - '0';
    }

    bfs();
}   