#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, T;
int room[50][50];
vector<pair<int, int>> a;
queue<pair<int, int>> q;
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

void init(){
  cin >> R >> C >> T;

  for(int r = 0; r < R; r++){
    for(int c = 0; c < C; c++) {
      cin >> room[r][c];
      if(room[r][c] == -1) a.push_back({r, c});
    }
  }
}

void microDust(){
  for(int r = 0; r < R; r++){
    for(int c = 0; c < C; c++){
      if(room[r][c]) q.push({r, c});
    }
  }

  int sz = q.size();

  int tRoom[51][51] = {0, };
  while(sz--){
    int curR = q.front().first;
    int curC = q.front().second;
    q.pop();

    int cnt = 0;
    for(int idx = 0; idx < 4; idx++){
      int nextR = curR + d[0][idx];
      int nextC = curC + d[1][idx];
      
      if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;

      if(room[nextR][nextC] == -1) continue;

      tRoom[nextR][nextC] += room[curR][curC] / 5;
      cnt++;
    }

    room[curR][curC] -= room[curR][curC] / 5 * cnt;
  }
  for(int r = 0; r < R; r++){
    for(int c = 0; c < C; c++) room[r][c] += tRoom[r][c];
  }
}

void airCleanerTop(){
  int aR = a[0].first;
  int aC = a[0].second;

  int tr = aR, tc = aC;  
  for(tr; tr > 0; tr--){
    if(room[tr][tc] == -1) room[tr - 1][tc] = 0;
    else room[tr][tc] = room[tr - 1][tc];
  }

  for(tc; tc < C - 1; tc++){
    if(room[tr][tc] == -1) room[tr][tc + 1] = 0;
    else room[tr][tc] = room[tr][tc + 1];
  }

  for(tr; tr < aR; tr++){
    room[tr][tc] = room[tr + 1][tc];
  }

  for(tc; tc > 0; tc--){
    if(room[tr][tc - 1] == -1) room[tr][tc] = 0;
    else room[tr][tc] = room[tr][tc - 1];
  }
}

void airCleanerBottom(){
  int aR = a[1].first;
  int aC = a[1].second;

  int tr = aR, tc = aC;  
  for(tr; tr < R - 1; tr++){
    if(room[tr][tc] == -1) room[tr + 1][tc] = 0;
    else room[tr][tc] = room[tr + 1][tc];
  }

  for(tc; tc < C - 1; tc++){
    if(room[tr][tc] == -1) room[tr][tc + 1] = 0;
    else room[tr][tc] = room[tr][tc + 1];
  }

  for(tr; tr > aR; tr--){
    room[tr][tc] = room[tr - 1][tc];
  }

  for(tc; tc > 0; tc--){
    if(room[tr][tc - 1] == -1) room[tr][tc] = 0;
    else room[tr][tc] = room[tr][tc - 1];
  }
}

void check(){
  int ans = 0;

  for(int r = 0; r < R; r++){
    for(int c = 0; c < C; c++){
      if(room[r][c] != -1) ans += room[r][c];
    }
  }

  cout << ans;
}

int main(){
  init();

  while(T--){
    microDust();

    airCleanerTop();

    airCleanerBottom();
  }

  check();
}