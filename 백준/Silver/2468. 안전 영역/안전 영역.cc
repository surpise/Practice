#include <iostream>
#include <queue>

using namespace std;

int arr[100][100];
int v[100][100];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int n, ans = 1, highest = 1;

void initV(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      v[i][j] = 0;
    }
  }
}

bool validXY(int x, int y){
  return (x >= 0 && x < n) && (y >= 0 && y < n);
}

void bfs(int h, queue<pair<int, int>> q){
  while(!q.empty()){
    int x = q.front().first, y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++){
      int tx = x + d[0][i], ty = y + d[1][i];
      if(validXY(tx, ty) && arr[tx][ty] > h && !v[tx][ty]){
        v[tx][ty] = 1;
        q.push({tx, ty});
      }
    }
  }
}

void solution(int h){
  initV();
  int cnt = 0;

  queue<pair<int, int>> q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(arr[i][j] > h && !v[i][j]){
        v[i][j] = 1;
        q.push({i, j});
        bfs(h, q);
        cnt++;
      }
    }
  }

  if(cnt > ans){
    ans = cnt;
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
      if(arr[i][j] > highest){
        highest = arr[i][j];
      }
    }
  }

  for(int i = 1; i <= highest; i++){
    solution(i);
  }
  cout << ans;
}