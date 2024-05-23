#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
typedef pair<pair<int, int>, int> PIII;

int n, m;
int arr[300][300];
queue<PII> q;
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

void melt(){
  int sz = q.size();
  queue<PIII> blankCntQ;

  for(int i = 0; i < sz; i++){
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();

    int blankCnt = 0;
    for(int idx = 0; idx < 4; idx++){
      int nextX = curX + d[0][idx];
      int nextY = curY + d[1][idx];

      if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
      if(arr[nextX][nextY] <= 0) blankCnt++;
    }

    blankCntQ.push({{curX, curY}, blankCnt});
  }

  while(!blankCntQ.empty()){
    int coordX = blankCntQ.front().first.first;
    int coordY = blankCntQ.front().first.second;
    int v = blankCntQ.front().second;
    blankCntQ.pop();

    arr[coordX][coordY] -= v;
    if(arr[coordX][coordY] > 0) q.push({coordX, coordY});
  }
}

bool isSeperate(){
  if(q.empty()) return false;

  queue<PII> tmpQ;
  bool visited[300][300] = {0, };
  int cnt = 1;

  int x = q.front().first;
  int y = q.front().second;
  tmpQ.push({x, y});
  visited[x][y] = 1;

  while(!tmpQ.empty()){
    x = tmpQ.front().first;
    y = tmpQ.front().second;
    tmpQ.pop();

    for(int idx = 0; idx < 4; idx++){
      int nextX = x + d[0][idx];
      int nextY = y + d[1][idx];

      if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
      if(arr[nextX][nextY] <= 0 || visited[nextX][nextY]) continue;

      visited[nextX][nextY] = 1;
      tmpQ.push({nextX, nextY});
      cnt++;
    }
  }

  if(cnt == q.size()) return false;
  else return true;
}

int main(){
  cin >> n >> m;
  for(int r = 0; r < n; r++){
    for(int c = 0; c < m; c++) {
      cin >> arr[r][c];
      if(arr[r][c]) q.push({r, c});
    }
  }

  int cnt = 0, ans = 0;
  while(!q.empty()){
    melt();
    cnt++;

    if(isSeperate()) {
      ans = cnt;
      break;
    }
  }
  
  cout << ans;
}