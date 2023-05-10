#include<vector>
#include <queue>

using namespace std;

vector<vector<int>> arr;
int v[101][101];
int n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

void bfs(){
    int y = q.front().first, x = q.front().second;
    q.pop();
    if(y == n && x == m){
        while(!q.empty()) q.pop();
        return;
    }

    for(int i = 0; i < 4; i++){
        if(y + dy[i] < 0 || y + dy[i] > n || x + dx[i] < 0 || x + dx[i] > m){
            continue;
        }
        if(!v[y + dy[i]][x + dx[i]] && arr[y + dy[i]][x + dx[i]] == 1) {
            q.push({y + dy[i], x + dx[i]});
            v[y+dy[i]][x + dx[i]] = v[y][x] + 1;
        }
    }
}

int solution(vector<vector<int>> maps)
{
    arr = maps;
    int answer = -1;
    n = maps.size() - 1;
    m = maps[0].size() - 1;

    q.push({0, 0});
    v[0][0] = 1;
    while(!q.empty()) bfs();
    if(v[n][m]) answer = v[n][m];
    return answer;
}