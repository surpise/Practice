#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int ans = 9999;
int n, m, blank;
int lab[50][50];
vector<PII> virus;
bool ck[50][50];
PII arr[10];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

void init(){
  cin >> n >> m;

  for(int row = 0; row < n; row++){
    for(int col = 0; col < n; col++) {
      cin >> lab[row][col];

      if(lab[row][col] == 2) virus.push_back({row, col});

      else if(lab[row][col] == 0) blank++;
    }
  }
}

void bfs(){
  int t = 0;
  int tBlank = blank;
  queue<PIII> q;
  bool visited[50][50] = {0, };
  for(int idx = 0; idx < m; idx++) {
    q.push({arr[idx], 0});
    visited[arr[idx].first][arr[idx].second] = 1;
  }
  
  while(!q.empty()){
    int curRow = q.front().first.first;
    int curCol = q.front().first.second;
    int time = q.front().second;
    q.pop();

    if(time >= ans) return;

    for(int idx = 0; idx < 4; idx++){
      int nextRow = curRow + d[0][idx];
      int nextCol = curCol + d[1][idx];
      int nextTime;


      if(nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n) continue;

      if(lab[nextRow][nextCol] == 1) continue;
      else nextTime = time + 1;

      if(!visited[nextRow][nextCol]){
        if(lab[nextRow][nextCol] == 0) tBlank--;
        t = max(t, nextTime);

        if(tBlank == 0) {
          if(ans > t) ans = t;
          return;
        }

        q.push({{nextRow, nextCol}, nextTime});
        visited[nextRow][nextCol] = 1;
      }
    }
  }
}

void solution(int cnt, int next){
  if(cnt == m){
    bfs();
    return;
  }

  for(int idx = next; idx < virus.size(); idx++){
    int row = virus[idx].first;
    int col = virus[idx].second;

    if(!ck[row][col]){
      ck[row][col] = 1;
      arr[cnt] = {row, col};
      solution(cnt + 1, idx + 1);
      ck[row][col] = 0;
    }
  }
}

int main(){
  init();

  solution(0, 0);

  if(blank == 0) cout << 0;
  else if(ans == 9999) cout << -1;
  else cout << ans;
}